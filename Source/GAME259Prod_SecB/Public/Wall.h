// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class GAME259PROD_SECB_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

	UStaticMeshComponent* wallMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

private:

public:	
	UFUNCTION()
	void Initialize();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetWallMaterial(UMaterialInstanceDynamic* mat);

};
