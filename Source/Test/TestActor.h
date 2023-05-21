// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuncLibrary/MyBlueprintFunctionLibrary.h"
#include "GameFramework/Actor.h"

#include "TestActor.generated.h"

UCLASS()
class TEST_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// my variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test", meta = (ToolTip = "Тестовый инт"))
	int32 intBlueprintReadWrite = 7;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Test")
	int32 intBlueprintReadOnly = 7;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Test")
	int32 intVisibleAnywhere = 7;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	bool AdditionalOption = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test", meta = (EditCondition = AddiTionalOption, EditConditionHides))
	int32 intAdditionalOption = 7;

	// сам энумератор в MyBlueprintFunctionLibrary
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	EMyEnumerator CoolEnumerator = EMyEnumerator::v1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test", meta = (EditCondition = "CoolEnumerator == EMyEnumerator::v3", EditConditionHides))
	int32 intAdditionalOption2 = 7;

	// my function
	UFUNCTION(BlueprintCallable, Category = "Test", meta = (Keywords = "my, function, example", Tooltip = "This is an example function"))
	void MyBlueprintCallableFunction();

	UFUNCTION(BlueprintPure, Category = "Test")
	int32 MyBlueprintPureFunction();

	UFUNCTION(BlueprintImplementableEvent, Category = "Test")
	void MyBlueprintImplementableEventFunction();

	UFUNCTION(BlueprintNativeEvent, Category = "Test")
	void MyBlueprintNativeEventFunction();

	UFUNCTION(BlueprintPure, Category = "Test")
	int32 MyFastBlueprintPureReturnFunction(){ return 8; }

	UFUNCTION(BlueprintCallable, Category = "Test")
	int MyBlueprintCallableParameterReturnFunction(int32 x, float y, FString z);

	UFUNCTION(BlueprintPure, Category = "Test")
	int32 MyBlueprintPureParameterReturnFunction(int32 x, float y, FString z);

	UFUNCTION()
	void JustMyParameterFunction(int32 x, float y, FString z);
};
