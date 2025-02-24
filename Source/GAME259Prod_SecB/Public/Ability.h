// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability.generated.h"

UENUM(BlueprintType)
enum class Type : uint8 {
    OFFENSIVE = 0 UMETA(DisplayName = "Offensive"),
    DEFENSIVE = 1  UMETA(DisplayName = "Defensive"),
};

UCLASS(BlueprintType)
class GAME259PROD_SECB_API AAbility : public AActor
{
    GENERATED_BODY()
public:
    AAbility();
    ~AAbility();

    //Can be used by any ability that need a value.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
    float floatValue;

    UFUNCTION(NetMulticast, Reliable, WithValidation)
    virtual void Activate();

    UFUNCTION(BlueprintCallable, Category = Status)
    UTexture2D* GetIcon();

    UFUNCTION(BlueprintCallable, Category = Status)
    Type GetType();

    bool CanUse() const;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
    FString imagePath;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Status)
    Type type;

    float cooldownTime;

    float remainingTime;
};