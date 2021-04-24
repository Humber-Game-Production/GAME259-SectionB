// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"
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
	//SetActorTickEnabled(true);

	//Create Sphere
	Bounds = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Bounds->SetSimulatePhysics(true);
	Bounds->InitSphereRadius(20.0f);
	Bounds->SetCollisionProfileName(FName("PhysicsActor"), false);
	Bounds->IgnoreActorWhenMoving(this, true);
	Bounds->SetVisibility(true);
	Bounds->OnComponentHit.AddDynamic(this, &ARocket::OnHit);
	Bounds->SetNotifyRigidBodyCollision(true);


	//Add Static Mesh Here
	UStaticMeshComponent* WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere")); 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/ProjectAmulet/Maps/Assets/StaticMesh/Weapons/Bazookarocket_Weapon_SM.Bazookarocket_Weapon_SM'"));

	WeaponMesh->SetStaticMesh(mesh.Object);
	WeaponMesh->SetWorldRotation(FRotator(90.0f, 0.0f, 0.0f));
	//Change collision type to Projectile
	WeaponMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	WeaponMesh->SetupAttachment(Bounds, "hm");

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovement->UpdatedComponent = Bounds;
	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->MaxSpeed = 2000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->Velocity.X = 2000.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	//Set Explosion Effect
	static ConstructorHelpers::FObjectFinder<UParticleSystem> BOOM(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	explosionEffect = BOOM.Object;

	static ConstructorHelpers::FObjectFinder<USoundWave> SoundEffect(TEXT("SoundWave'/Game/StarterContent/Audio/Explosion01.Explosion01'"));

	soundEffect = SoundEffect.Object;

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


	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), //WorldContext
		explosionEffect, //Particle Effect
		GetActorTransform(), //Location Transform
		true, //AutoDestroy
		EPSCPoolMethod::AutoRelease, //Particle Pooling Method
		true);

	UGameplayStatics::PlaySoundAtLocation(GetWorld(),//World Context
		soundEffect, //Sound Effect
		GetActorLocation() //Sound Location
		);

	/*
	DrawDebugSphere(GetWorld(),
		GetActorTransform().GetLocation(),
		300.0f,
		12,
		FColor::Red,
		false,
		1.0f,
		0,
		1.0f);
	*/

	Destroy();
}

