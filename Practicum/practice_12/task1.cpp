#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

const char* names[] = { "Katerina", "Milanka", "Vediha", "Dimana", "Teodor",
						"Stefan A.", "Luchezara", "Niya", "Toma", "Cveti", 
						"Martin N.", "Silviya", "Dimitar", "Kalina", "Gabi", "Rado",
						"Svetoslav", "Kiril", "Martin D." ,"Vladi", "Luben",
						"Stefan H.", "Annamaria" };

const size_t students_count = 23;


const char* actions[] = { " prepodava na ", " smee se na ", " gazi ", " celuva :* ",
						  " skacha vurhu ", " chupi krusta na ", " hodi na diskoteka s " };

const size_t actions_count = 7;

void generateAction() {
	
	const char* s1 = names[rand() % students_count];
	const char* s2 = names[rand() % students_count];
	const char* action = actions[rand() % actions_count];

	char* str = new(std::nothrow) char[strlen(s1) + strlen(s2) + strlen(action) + 1];
	strcpy(str, s1);
	strcat(str, action);
	strcat(str, s2);

	std::cout << str << std::endl;

	delete[] str;

}


int main() {
	// А) Изпишете срещу името на всеки колко е дължината му
	// Пример:
	// Katerina - 8
	// Milanka - 7
	// ....


	for(int i = 0; i < students_count; ++i) {
		std::cout << names[i] << " - " << strlen(names[i]) << std::endl;
	}

	// Б) Добавете нови действия в масива с действия
	
	// В) Изберете на рандом един студент, едно действие и още един студент
	// Заделете точно толкова динамична памет, колкото е нужно, че да запишете
	// двете имена и действието в нея. Изпишете полученото изречение на екрана.
	srand(time(NULL));	
	generateAction();

	// Г) Въведете цяло положително число N от клавиатурата.
	// Направете N изречения от горният вид.

	size_t N;
	std::cin >> N;

	for(int i = 0; i < N; ++i) {
		generateAction();	
	}

	return 0;
}
