#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
std::string count(int number, int flag) {

std::string result;
std::string mil[2] = { "один","два"};
if (flag == 0) {
	mil[0] = "одна";
	mil[1] = "две";
}
if (number / 10 % 10 == 1) {
	switch (number % 10) {
	case 1:
		result = "одинадцать" + result;
		break;
	case 2:
		result = "двенадцать" + result;
		break;
	case 3:
		result = "тринадцать" + result;
		break;
	case 4:
		result = "четырнадцать" + result;
		break;
	case 5:
		result = "пятьнадцать" + result;
		break;
	case 6:
		result = "шестьнадцать" + result;
		break;
	case 7:
		result = "семьнадцать" + result;
		break;
	case 8:
		result = "восемьнадцать" + result;
		break;
	case 9:
		result = "девятьнадцать" + result;
		break;
	case 0:
		result = "десять" + result;
		break;
	}
	number /= 100;
}

else {
	switch (number % 10) {
	case 1:
		result = mil[0] + result;
		break;
	case 2:
		result = mil[1] + result;
		break;
	case 3:
		result = "три" + result;
		break;
	case 4:
		result = "четыре" + result;
		break;
	case 5:
		result = "пять" + result;
		break;
	case 6:
		result = "шесть" + result;
		break;
	case 7:
		result = "семь" + result;
		break;
	case 8:
		result = "восемь" + result;
		break;
	case 9:
		result = "девять" + result;
		break;
	case 0:
		break;
	}
	number /= 10;
	switch (number % 10) {
	case 2:
		result = "двадцать " + result;
		break;
	case 3:
		result = "тридцать " + result;
		break;
	case 4:
		result = "сорок " + result;
		break;
	case 5:
		result = "пятьдесят " + result;
		break;
	case 6:
		result = "шестьдесят " + result;
		break;
	case 7:
		result = "семьдесят " + result;
		break;
	case 8:
		result = "восемьдесят " + result;
		break;
	case 9:
		result = "девяносто " + result;
		break;
	case 0:
		break;
	}
	number /= 10;
}


	switch (number % 10) {
	case 1:
		result = "сто " + result;
		break;
	case 2:
		result = "двести " + result;
		break;
	case 3:
		result = "триста " + result;
		break;
	case 4:
		result = "четырста " + result;
		break;
	case 5:
		result = "пятьсот " + result;
		break;
	case 6:
		result = "шестьсот " + result;
		break;
	case 7:
		result = "семьсот " + result;
		break;
	case 8:
		result = "восемьсот " + result;
		break;
	case 9:
		result = "девятьсот " + result;
		break;
	case 0:
		break;
	}

	return result;
}
int GetRandomNumber(int min, int max)
{
	// Установить генератор случайных чисел
	srand(time(NULL));

	// Получить случайное число - формула
	int num = min + rand() % (max - min + 1);

	return num;
}
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	uint32_t numOfGooses = std::atoi(argv[1]);
	if (numOfGooses == 0)
	{
		std::cout << "Во дворе нет гусей.";
		return 0;
	}

	std::string final;
	std::string goose[3] = { "гусь.","гуся.","гусей." };
	std::string single[3] = { "тысяча","миллион","миллиард", };
	std::string between2_4[3] = { "тысячи","миллиона","миллиарда", };
	std::string between5_9[3] = { "тысяч","миллионов","миллиардов",};

	if (numOfGooses / 10 % 10 == 1)
	final = count(numOfGooses % 1000, 1) + " " + goose[2];
	else if (numOfGooses % 10 == 1)
		final = count(numOfGooses % 1000,1)+ " " + goose[0];
	else if (numOfGooses /10%10 == 1)
		final = count(numOfGooses % 1000, 1) + " " + goose[2];
	else if (numOfGooses % 10 == 2 || numOfGooses % 10 == 3 || numOfGooses % 10 == 4)
		final = count(numOfGooses % 1000,1) + " " +  goose[1];
	else
		final = count(numOfGooses % 1000,1) + " " + goose[2];

	numOfGooses /= 1000;

	for (int i = 0; i < 3; i++) {
		if (numOfGooses % 1000 == 0) {
			numOfGooses /= 1000;
			continue;
		}
		
		if (numOfGooses / 10 % 10 == 1)
			final = count(numOfGooses % 1000, i) + " " + between5_9[i] + " " + final;
		else if (numOfGooses % 10 == 1)
			final = count(numOfGooses % 1000, i) + " " + single[i] + " " + final;
		else if(numOfGooses % 10 == 2 || numOfGooses % 10 == 3 || numOfGooses % 10 == 4  )
			final = count(numOfGooses % 1000,i) + " " + between2_4[i] + " " + final;
		else 
			final = count(numOfGooses % 1000,i) + " " + between5_9[i] + " " + final;
		numOfGooses /= 1000;
	}
	std::cout << " Во дворе " << final  <<std::endl;
	return 0;
}