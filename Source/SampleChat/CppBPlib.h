// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CppBPlib.generated.h"

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
	static void CheckResult(const FString& Message);
};
