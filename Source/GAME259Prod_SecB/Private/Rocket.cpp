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
	
	SetActorEnableCollision(true);

	//Create Sphere
	Bounds = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Bounds->SetSimulatePhysics(true);
	Bounds->InitSphereRadius(20.0f);
	Bounds->SetCollisionProfileName(FName("PhysicsActor"), false);
	Bounds->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	//Bounds->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Ignore);
	Bounds->IgnoreActorWhenMoving(this, true);
	Bounds->SetVisibility(true);
	Bounds->OnComponentHit.AddDynamic(this, &ARocket::OnHit);
	Bounds->SetNotifyRigidBodyCollision(true);

	//Game / ProjectAmulet / Maps / Assets / StaticMesh / Weapons / Bazookarocket_Weapon_SM
	//Add Static Mesh Here
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere")); //Bounds->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	WeaponMesh->SetStaticMesh(mesh.Object);
	WeaponMesh->SetWorldScale3D(FVector(0.2f, 0.2f, 0.4f));
	WeaponMesh->SetWorldRotation(FRotator(0.0f, 0.0f, 90.0f));
	//Change collision type to Projectile
	WeaponMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	WeaponMesh->SetupAttachment(Bounds,"hm");

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovement->UpdatedComponent = Bounds;
	ProjectileMovement->InitialSpeed = 1000.f;
	ProjectileMovement->MaxSpeed = 1000.0f;
	ProjectileMovement->bRotationFollowsVelocity = false;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->Velocity.X = 1.0f;

      // set up a notification for when this component overlaps something

	//TODO: find way to pass in parameter to allow for dynamic damage
	damage = 30.0f;

	//Set Tag.
	Tags.Add("Rocket");

	bReplicates = false;

	//TODO: SetLifeTime Limit?
}

void ARocket::Initalize(float damage_) {
	damage = damage_;
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

void ARocket::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()

	const TArray<AActor*> actorIgnore{  };

	TSubclassOf<UDamageType> dam;


	//Explosion
	UGameplayStatics::ApplyRadialDamage(GetWorld(), //World instance
		damage, //Damage Applied
		GetActorLocation(), //Point Of Explosion
		300.0f, //Explosion Radius
		dam, //Damage type info
		actorIgnore, //Actors to ignore
		this,
		nullptr,
		false,
		ECollisionChannel::ECC_Visibility);

	DrawDebugSphere(GetWorld(),
		GetActorTransform().GetLocation(),
		300.0f,
		12,
		FColor::Red,
		false,
		1.0f,
		0,
		1.0f);

	Destroy();
}
