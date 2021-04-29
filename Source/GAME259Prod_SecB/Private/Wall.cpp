// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(true);

	 wallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	
	 static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/ProjectAmulet/Maps/Assets/StaticMesh/Weapons/DWC_Deployable_Shield.DWC_Deployable_Shield'"));

	 wallMesh->SetStaticMesh(mesh.Object);

	 wallMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWall::Initialize()
{
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void AWall::SetWallMaterial(UMaterialInstanceDynamic* mat)
{
	wallMesh->SetMaterial(0,mat);
}

