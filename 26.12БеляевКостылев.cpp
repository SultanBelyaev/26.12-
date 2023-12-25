#include <vector>
#include <iostream>

double* array_storage(int length_array1) {
	double* array = new double[length_array1];
	return array;
}

void array_el(double* array, int length_array1) {
	for (int i = 0; i < length_array1; i++) {
		array[i] = rand();
	}
}

void array_elshow(double* array, int length_array1) {
	for (int i = 0; i < length_array1; i++) {
		std::cout << array[i] << "  ";
	}
	std::cout << std::endl;
}

void delete_storagedouble(double* array1) {
	delete[] array1;
	array1 = 0;

	std::cout << "Stotage is empty" << std::endl;
}

void delete_storageint(int* array1) {
	delete[] array1;
	array1 = 0;

	std::cout << "Stotage is empty" << std::endl;
}

void int_array_el(int* array) {
	for (int i = 0; i < 12; i++) {
		array[i] = rand();
	}
}

void int_array_elshow(int* array) {
	for (int i = 0; i < 12; i++) {
		std::cout << array[i] << "  ";
	}
	std::cout << std::endl;
}

void swap_el(int* array) {
	for (int i = 0; i < 11; i = i + 2) {
		int k = 0;
		k = array[i];
		array[i] = array[i + 1];
		array[i + 1] = k;
	}
}


int main() {

	//Task 1

	long int value1 = 1234567;
	float const value2 = 45.45667;
	char value3 = 122;
	unsigned int value4 = 64234459;
	double value5 = 1653.328743;


	const float* const ptr_floatconst = &value2;

	typedef long int* ptr_longinttype;
	ptr_longinttype ptr_lc = &value1;

	double* ptr_double;

	const short int* ptr_shortint;

	typedef const float* const ptr_floatconst_type;
	ptr_floatconst_type ptr_fc = &value2;

	typedef char* prt_char_type;
	prt_char_type prt_c = &value3;

	double* const ptr_doubleconst = &value5;

	typedef const unsigned int* ptr_unsignedint_type;
	ptr_unsignedint_type ptr_ui = &value4;




	//Task 2

	int length_array1;

	std::cout << "Task 2" << std::endl << std::endl;

	std::cout << "Enter the number of elements in array (to finish enter 9999): " << std::endl;
	std::cin >> length_array1;

	while (length_array1 != 9999) {
		double* array1 = array_storage(length_array1);
		array_el(array1, length_array1);
		array_elshow(array1, length_array1);
		delete_storagedouble(array1);

		std::cout << "Enter the number of elements in array (to finish enter 9999): " << std::endl;
		std::cin >> length_array1;
	}




	//Task 3
	std::cout << "Task 3" << std::endl << std::endl;

	int* array2 = new int[12];
	int_array_el(array2);
	std::cout << "First array:" << std::endl;
	int_array_elshow(array2);

	swap_el(array2);

	std::cout << "Changed array:" << std::endl;
	int_array_elshow(array2);


	delete_storageint(array2);


	return 0;
}
/*Объявить и заполнить двумерный динамический массив случайными числами от 10 до 50. Показать его на экран. 
Для заполнения и показа на экран написать отдельные функции. 
(подсказка: функции должны принимать три параметра – указатель на динамический массив, количество строк, количество столбцов). 
Количество строк и столбцов выбирает пользователь. */


// 4 задание
void toFullArray(int** array, int row, int column) {
	srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = 10 + rand() % 50;
		}
	}
};

void toSnowArray(int** array, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
};

void Task4() {
	const int ROW_ARRAY = 10;
	const int COLUMN_ARRAY = 10;
	int** array = new int* [ROW_ARRAY];

	//Создание массива
	for (int i = 0; i < ROW_ARRAY; i++) {
		array[i] = new int[COLUMN_ARRAY];
	}

	//Заполнение
	toFullArray(array, ROW_ARRAY, COLUMN_ARRAY);

	std::cout << std::endl;

	//Вывод
	toSnowArray(array, ROW_ARRAY, COLUMN_ARRAY);

	for (int i = 0; i < ROW_ARRAY; i++) {
		delete[] array[i];
	}
	delete[] array;
};



// 5 задание
int doAddition(int a, int b) {
	return a + b;
};

int doSubtraction(int a, int b) {
	return a - b;
};

int doMultiplication(int a, int b) {
	return a * b;
};

int doDivision(int a, int b) {
	return a / b;
};

void Task5() {
	int var1 = 0;
	int var2 = 0;
	char varOperator = 0;

	std::cout << "Введите первую переменную" << std::endl;
	std::cin >> var1;
	std::cout << "Введите вторую переменную" << std::endl;
	std::cin >> var2;
	std::cout << "Введите оператор" << std::endl;
	std::cin >> varOperator;

	int (*fcnPtr)(int, int) = nullptr;
	int fcnOutput = NULL;

	while (varOperator == '+' || varOperator == '-' || varOperator == '/' || varOperator == '*') {
		switch (varOperator) {
		case '+':
			fcnPtr = doAddition;
			fcnOutput = fcnPtr(var1, var2);
			std::cout << fcnOutput << std::endl;

			std::cout << "Вновь введите первую переменную" << std::endl;
			std::cin >> var1;
			std::cout << "Вновь введите вторую переменную" << std::endl;
			std::cin >> var2;
			std::cout << "Вновь введите оператор" << std::endl;
			std::cin >> varOperator;
			break;
		case '-':
			fcnPtr = doSubtraction;
			fcnOutput = fcnPtr(var1, var2);
			std::cout << fcnOutput << std::endl;

			std::cout << "Вновь введите первую переменную" << std::endl;
			std::cin >> var1;
			std::cout << "Вновь введите вторую переменную" << std::endl;
			std::cin >> var2;
			std::cout << "Вновь введите оператор" << std::endl;
			std::cin >> varOperator;
			break;
		case '*':
			fcnPtr = doMultiplication;
			fcnOutput = fcnPtr(var1, var2);
			std::cout << fcnOutput << std::endl;

			std::cout << "Вновь введите первую переменную" << std::endl;
			std::cin >> var1;
			std::cout << "Вновь введите вторую переменную" << std::endl;
			std::cin >> var2;
			std::cout << "Вновь введите оператор" << std::endl;
			std::cin >> varOperator;
			break;
		case '/':
			fcnPtr = doDivision;
			fcnOutput = fcnPtr(var1, var2);
			std::cout << fcnOutput << std::endl;

			std::cout << "Вновь введите первую переменную" << std::endl;
			std::cin >> var1;
			std::cout << "Вновь введите вторую переменную" << std::endl;
			std::cin >> var2;
			std::cout << "Вновь введите оператор" << std::endl;
			std::cin >> varOperator;
			break;
		default:
			break;
		}
	}
	std::cout << "Конец!" << std::endl; // только при вводе 32, т.к. формат char автоматически переводит в символы
};



// 7 задание
void Task7(std::vector<int>& nums) {
	int count = 0;
	int answer = 0;

	for (int num : nums) {
		if (count == 0) {
			answer = num;
		}

		if (num == answer) {
			count++;
		}
		else {
			count--;
		}
	}

	std::cout << answer << std::endl;;
};


int main() {
	setlocale(LC_ALL, "RU");

	/* Task 4 */
	/* Объявить и заполнить двумерный динамический массив случайными числами от 10 до 50.
	Показать его на экран. Для заполнения и показа на экран написать отдельные функции. 
	(подсказка: функции должны принимать три параметра – указатель на динамический массив, количество строк, количество столбцов). Количество строк и столбцов выбирает пользователь. */
	std::cout << "Result of 4 task" << std::endl;
	Task4();
	std::cout << std::endl;	

	/* Task 5 */
	/* Решите задачу, используя один указатель на функцию. Разработайте четыре функции над двумя целыми параметрами, соответствующие арифметическим операциям (+, -, *, /). 
	В основной программе задавайте два целых параметра и символьный знак операции до тех пор, пока не будет введен пробел в качестве знака операции. В выходных данных выводите значения функций.  */
	std::cout << "Result of 5 task" << std::endl;
	Task5();
	std::cout << std::endl;

	/* Task 7 */
	/* https://leetcode.com/problems/find-lucky-integer-in-an-array/ */
	std::cout << "Result of 7 task" << std::endl;
	std::vector<int> vectorArray = { 1,2,2,3,3,3 };
	Task7(vectorArray);
	std::cout << std::endl;
	return 0;
}

/* Task 6 */

class Solution {
public:
	int minimumDifference(vector<int>& A, int k) {
		sort(begin(A), end(A));
		int ans = INT_MAX;
		for (int i = 0; i <= A.size() - k; ++i) {
			ans = min(ans, A[i + k - 1] - A[i]);
		}
		return ans;
	}
};


/* Task 8 */

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int ans = 0, cnt = 0;
		for (int n : nums) {
			if (ans == n) ++cnt;
			else if (cnt > 0) --cnt;
			else {
				ans = n;
				cnt = 1;
			}
		}
		return ans;
	}
};