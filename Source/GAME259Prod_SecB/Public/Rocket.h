// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Rocket.generated.h"


UCLASS()
class GAME259PROD_SECB_API ARocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocket();

	UFUNCTION()
	void Initalize(float damage_); //Used to initalize the object.

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float damage;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	/** sphere component */
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USphereComponent* Bounds;



};
