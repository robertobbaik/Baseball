// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBPlib.h"
#include "Algo/RandomShuffle.h"

int32 UCppBPlib::GetRandomNum()
{
	int32 Num = FMath::RandRange(1, 9);
	return Num;
}

TArray<int32> UCppBPlib::GetRandomArray(int Size)
{
	TArray<int32> Temp;
	for (int i = 1; i < 10; ++i)
	{
		Temp.Add(i);
	}

	Algo::RandomShuffle(Temp);

	TArray<int32> Result;

	for (int i = 0; i < Size; ++i)
	{
		Result.Add(Temp[i]);
	}

	return Result;
}

FString UCppBPlib::GetRandomArrayToString(const TArray<int32>& Array)
{
	FString Str = "";
	for (int Num : Array)
	{
		Str += FString::FromInt(Num);
	}

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Str);

	return Str;
}

FString UCppBPlib::TakeMessage(const FString& Message, const TArray<int32>& CorrectAnswer)
{
	if (Message.Contains("/"))
	{
		FString Left, Right;
		if (Message.Split(TEXT("/"), &Left, &Right))
		{
			TArray<int32> Temp;

			for (char c : Right)
			{
				int32 i = c - '0';
				Temp.Add(i);
			}

			FString Str = "";

			int BallCount = 0;
			int StrikeCount = 0;

			for (int32 Num : Temp)
			{
				Str.Append(FString::FromInt(Num));
				
			}

			if (Temp.Num() != CorrectAnswer.Num()) return TEXT("NONE");

			for (int i = 0; i < Temp.Num(); ++i)
			{
				for (int j = 0; j < Temp.Num(); ++j)
				{
					if (Temp[i] == CorrectAnswer[j])
					{
						if (i == j)
						{
							StrikeCount++;
						}
						else
						{
							BallCount++;
						}
					}
				}
			}

			if (StrikeCount == 0 && BallCount == 0)
			{
				return TEXT("OUT");
			}
			else
			{
				return FString::Printf(TEXT("%d Strike, %d Ball"), StrikeCount, BallCount);
			}

			//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("%s"), *Str));
		}
	}
	else
	{
		return TEXT("None");
	}
	return TEXT("NONE");
}

void UCppBPlib::CheckResult(const FString& Message)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Answer")));
}

