// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CppBPlib.generated.h"

UENUM(BlueprintType) // BlueprintType: 블루프린트에서 사용 가능하게 함
enum class EMessageType : uint8
{
	QUESTION        UMETA(DisplayName = "Question"),
	ANSWER     UMETA(DisplayName = "Answer"),
	NONE     UMETA(DisplayName = "None"),
};

/**
 * 
 */
UCLASS()
class SAMPLECHAT_API UCppBPlib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Message")
	static int32 GetRandomNum();

	UFUNCTION(BlueprintCallable, Category = "Message")
	static TArray<int32> GetRandomArray(int Size);

	UFUNCTION(BlueprintCallable, Category = "Message")
	static FString GetRandomArrayToString(const TArray<int32>& Array);

	UFUNCTION(BlueprintCallable, Category = "Message")
	static FString TakeMessage(const FString& Message, const  TArray<int32>& CorrectAnswer);

	UFUNCTION(BlueprintCallable, Category = "Message")
	static EMessageType Message(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "Message")
	static FString CaculateAnswer(const FString& Message, const TArray<int32> CorrectAnswer);

	UFUNCTION(BlueprintCallable, Category = "Message")
	static FString PrintAnswer(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "Message")
	static void CheckResult(const FString& Message);
};
