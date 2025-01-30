/*
Author - Lukas Kubinec
Description - Chooses random string from array and returns it as casted Text
*/
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChooseRandomString.generated.h"

/**
 * 
 */
UCLASS()
class CPP_PROJECT_API UChooseRandomString : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:
	// Chooses a random string from array
	UFUNCTION(BlueprintCallable, Category = "Random")
	static FText ChooseRandomString(TArray<FString> StringsArray);
	
};
