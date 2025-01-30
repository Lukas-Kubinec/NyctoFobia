/*
Author - Lukas Kubinec
Description - Chooses random string from array and returns it as casted Text
*/

#include "ChooseRandomString.h"
#include <Kismet/KismetMathLibrary.h>


FText UChooseRandomString::ChooseRandomString(TArray<FString> StringsArray)
{
	// Gets the lenght of array
	int32 _arrayLen = StringsArray.Num() - 1; // -1 because arrays start at 0

	// Used to randomly select string from array
	int32 _randomInt = UKismetMathLibrary::RandomIntegerInRange(0, _arrayLen);

	// Return is a randomly chosen Text casted from the String array
	return FText::FromString(StringsArray[_randomInt]);
}
