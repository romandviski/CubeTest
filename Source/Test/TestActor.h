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
	
private: // доступ открыт только самому классу

	// Приватная переменная
	int SecretInt = 666;
	
public:	// доступ открыт всем другим классам, кто видит определение данного класса

	// Sets default values for this actor's properties
	ATestActor();

protected: // доступ открыт классам, производным от данного. (наследникам)

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Вызывается после инициализации переменных
	virtual void PostInitProperties() override;
	// Вызывается после изменений в редакторе
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

public:
// Мои переменные =========================================================================================================
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test", meta = (ToolTip = "Тестовый инт"))
	int32 intBlueprintReadWrite = 2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Test")
	int32 intBlueprintReadOnly = 3;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Test")
	int32 intVisibleAnywhere = 777;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	bool AdditionalOption = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test", meta = (EditCondition = AddiTionalOption, EditConditionHides))
	int32 intAdditionalOption = 7;

	// Энумератор описан в MyBlueprintFunctionLibrary
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	EMyEnumerator CoolEnumerator = EMyEnumerator::v1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test", meta = (EditCondition = "CoolEnumerator == EMyEnumerator::v3", EditConditionHides))
	int32 intAdditionalOption2 = 7;

	// Пример для PostInitProperties в связке с PostEditChangeProperty
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test2")
	float BaseDamage = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test2")
	float Multiplier = 3;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Test2")
	float FinalDamage = 777;
	
// Мои функции =========================================================================================================

	// Функция объявленная в С++
	UFUNCTION(BlueprintCallable, Category = "Test", meta = (Keywords = "my, function, example", Tooltip = "This is an example function"))
	void MyBlueprintCallableFunction();

	// Пьюр функция без входа объявленная в С++
	UFUNCTION(BlueprintPure, Category = "Test")
	int32 MyBlueprintPureFunction();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Test", meta = (ToolTip = "Логика только в блюпринте"))
	void MyBlueprintImplementableEventFunction();

	/*
	  Часть логики в С++, продолжение в блюпринте
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "Test", meta = (Keywords = "777, fun"))
	void MyBlueprintNativeEventFunction();

	// FORCEINLINE - Если компилятор решает, что встраивание возможно и целесообразно, 
	// то он заменяет каждый вызов функции на непосредственное вставление кода функции в место вызова.
	// const - функция гарантирует, что она не изменит состояние объекта класса, к которому она принадлежит.
	UFUNCTION(BlueprintPure, Category = "Test")
	FORCEINLINE int32 MyFastBlueprintPureReturnFunction() const { return SecretInt; }

	UFUNCTION(BlueprintCallable, Category = "Test")
	int MyBlueprintCallableParameterReturnFunction(int32 x, float y, FString z);

	UFUNCTION(BlueprintPure, Category = "Test")
	int32 MyBlueprintPureParameterReturnFunction(int32 x, float y, FString z);

	// Ещё примеры	https://nerivec.github.io/old-ue4-wiki/pages/custom-blueprint-node-creation.html
	// Зачем нужен static https://habr.com/ru/articles/527044/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Adds floats", CompactNodeTitle = "Add Floats", Keywords = "Float Add"), Category = Test)
	float AddFloats(float fA = 0.1f, float fB = 0.2f);
	
	// Функция о которой ничего не знает блюпринт
	UFUNCTION()
	void JustMyParameterFunction(int32 x, float y, FString z);
};
