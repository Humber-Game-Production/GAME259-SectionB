// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"
#include "UObject/UObjectGlobals.h"
#include "../GAME259Prod_SecBCharacter.h"


// Sets default values
ARocket::ARocket()
{
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Create Sphere
	Bounds = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Bounds->InitSphereRadius(20.0f);
	Bounds->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	Bounds->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);
	Bounds->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	Bounds->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Ignore);
	Bounds->SetVisibility(true);


	
	//Add Static Mesh Here
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere")); //Bounds->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	//static UStaticMeshComponent* WeaponMesh = FObjectInitializer::CreateDefaultSubobject<UStaticMeshComponent>(Bounds, TEXT("Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	WeaponMesh->SetStaticMesh(mesh.Object);
	WeaponMesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.4f));
	WeaponMesh->SetWorldRotation(FRotator(0.0f, 0.0f, 90.0f));
	//Change collision type to Projectile
	WeaponMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	WeaponMesh->SetupAttachment(Bounds,"hm");
	//Bounds->SetupAttachment(WeaponMesh);


	

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovement->UpdatedComponent = Bounds;
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->MaxSpeed = 1000.0f;
	ProjectileMovement->bRotationFollowsVelocity = false;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->Velocity.X = 1.0f;

	Bounds->OnComponentBeginOverlap.AddDynamic(this, &ARocket::OnSphereBeginOverlap);
      // set up a notification for when this component overlaps something

	//TODO: find way to pass in parameter to allow for dynamic damage
	damage = 30.0f;

	//Set Tag.
	Tags.Add("Rocket");

}

// Called when the game starts or when spawned
void ARocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARocket::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		//Would this method add pawn?
		TArray<TEnumAsByte<EObjectTypeQuery>> objTypes;
		objTypes.Add(EObjectTypeQuery::ObjectTypeQuery2);

		const TArray<AActor*> actorIgnore{ UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn() };
		TArray<AActor*> actorOut;

		//Explosion
		UKismetSystemLibrary::SphereOverlapActors(GetWorld(),
			GetActorTransform().GetLocation(), //Position
			300.0f, //Radius
			objTypes, //Object List
			AGAME259Prod_SecBCharacter::StaticClass(), //Actor Class Filter
			actorIgnore, //Actor Ignore
			actorOut //Actor output
		);

		DrawDebugSphere(GetWorld(),
			GetActorTransform().GetLocation(),
			300.0f,
			12,
			FColor::Red,
			true,
			1.0f,
			0,
			1.0f);

		TSubclassOf<UDamageType> dam;

		for (auto var : actorOut)
		{
			if (OtherActor->ActorHasTag("Player")) {
				UGameplayStatics::ApplyDamage(var, //DamagedActor
					damage, //Damage value
					UGameplayStatics::GetPlayerController(GetWorld(), 0), //DamageInstigator
					nullptr, //DamageCauser
					dam);
			}
		}
}

