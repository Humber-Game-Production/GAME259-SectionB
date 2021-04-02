// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../GAME259Prod_SecBCharacter.h"


// Sets default values
ARocket::ARocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Bounds = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Bounds->InitSphereRadius(250.0f);

	//Add Static Mesh Here
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	WeaponMesh->SetStaticMesh(mesh.Object);
	WeaponMesh->AttachTo(Bounds);


	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovement->UpdatedComponent = WeaponMesh;
	ProjectileMovement->InitialSpeed = 100.f;
	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;


	Bounds->OnComponentBeginOverlap.AddDynamic(this, &ARocket::OnSphereBeginOverlap);
      // set up a notification for when this component overlaps something

	//TODO: find way to pass in parameter to allow for dynamic damage
	damage = 30.0f;
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

	const TArray<AActor*> actorIgnore;
	TArray<AActor*> actorOut;

	//Explosion
	UKismetSystemLibrary::SphereOverlapActors(this,
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorLocation(), //Position
		300.0f, //Radius
		objTypes, //Object List
		AGAME259Prod_SecBCharacter::StaticClass(), //Actor Class Filter
		actorIgnore, //Actor Ignore
		actorOut //Actor output
	);

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

