#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;
using namespace this_thread;
using namespace chrono;


class Person {

	public:
		int point_x;
		int point_y;
		Person() {
			point_x = 0;
			point_y = 0;
			id = "000";
			infection = false;
		}
		void set_id(string id);
		string get_id();
		void set_infection(bool infection);
		bool get_infection();

	private:
		string id;
		bool infection;
};

void Person::set_id(string id) {
	this->id = id;
}

string Person::get_id() {
	return this->id;
}

void Person::set_infection(bool infection) {
	this->infection = infection;
}

bool Person::get_infection() {
	return this->infection;
}

const int MAX_PEOPLE = 100; 
const int MAX_PLANE_SIZE = 100;
const int MIN_PLANE_SIZE = -100;
const int NUMBERSIZE = 10;
const int MAX_SHIFT_FORWARD = 1;
const int MAX_SHIFT_BACK = -1;
const int GRID_SIZE = 200;  
const int INITIAL_INFECTION_RATE = (MAX_PEOPLE * 10 / 100); //rate of initial total infected people
const int WIDTH_SPACE1 = 20;
const int WIDTH_SPACE2 = 18;
const int WIDTH_SPACE3 = 27;
const int WIDTH_SPACE4 = 10;
const int TIME_SLEEP = 5;
const int MAX_NUM_COUNT = 10;
const int MIN_NUM_COUNT = 1;
const int CRITICAL_DECISION_NUM = 1;

void generate_id(Person  people[], string number_array[]);
void location_and_infection(Person  people[], int& initial_infection_num);
int generate_rand_num(int max, int min);
void print_details(Person people[], int shift_x, int shift_y, int index);
void print_header(int j);
void correction_by_boundary(Person people[], int index, int& shift_x, int& shift_y);
bool nearby_infected_element(int target_x, int target_y, bool target, Person array[], int size1, int index);
void infection_simulation(char tracking[][GRID_SIZE], int num_of_days);
void populate_and_display_grid(Person people[], char tracking[][GRID_SIZE]);
string infection_status(Person people[], int index);
void total_infection(int initial_num, int num_of_days, int daily_infection_rate[]);

int main() {
	
	srand(time(NULL));
	Person people_detail[MAX_PEOPLE];
	string number_array[NUMBERSIZE] = { "0","1","2","3","4","5","6","7","8","9" };
	
	const int num_of_days = 15;
	int initial_infection_num = 0;

	generate_id(people_detail, number_array);//generates a unique id for each person
	location_and_infection(people_detail, initial_infection_num);// randomly locates and turns certain percent of the people infected

	char tracking[GRID_SIZE][GRID_SIZE];
	int daily_infection_rate[num_of_days] = {0};
	
	

	for (int j = 0; j < num_of_days; j++) {

		print_header(j);// prints header

		for (int i = 0; i < MAX_PEOPLE; i++) {

			int shift_x = 0, shift_y = 0;
			shift_x = generate_rand_num(MAX_SHIFT_FORWARD, MAX_SHIFT_BACK);//moves person location infront or back by 1, or no movement
			shift_y = generate_rand_num(MAX_SHIFT_FORWARD, MAX_SHIFT_BACK);//moves person location up or down by 1, or no movement
			people_detail[i].point_x += shift_x;//adds the shift to the person's locations
			people_detail[i].point_y += shift_y;//adds the shift to the person's locations

			
			correction_by_boundary(people_detail, i, shift_x, shift_y);//if person goes out of the plane then the position is corrected by bring it back in
			print_details( people_detail, shift_x, shift_y,i);// prints all the necessay detail

		}

		for (int h = 0; h < MAX_PEOPLE; h++) {

			int target_x = 0, target_y = 0;
			bool target = people_detail[h].get_infection();
			target_x = people_detail[h].point_x;
			target_y = people_detail[h].point_y;

			//checks if there is a element close to a particlular person
			if (  nearby_infected_element(target_x, target_y, target, people_detail, MAX_PEOPLE, h) == true) {
				
				int num_rando = generate_rand_num(MAX_NUM_COUNT, MIN_NUM_COUNT);
				/*there are 10 number, each representing 10%(1-10). anything number greater than 1 means that the person will get infected,
				meaning 9 numbers, 90% chance person will get infected and if the randomly generated number is 1 and the person will not be infected*/
				if (num_rando > CRITICAL_DECISION_NUM) {
					people_detail[h].set_infection(true);
					daily_infection_rate[j]++;
				}
			}
		}

		cout << endl << "Daily Infection : " << daily_infection_rate[j] << endl;// preints the daily infection number
		cout <<endl<< "FULLSCREEN CONSOLE WINDOW AND REDUCE TEXT SIZE" << endl;//intructions to maximize window and decrese text size
		cout << "\n'@' represents healthy person\n'T' represents infected person\n\n";//legends
		system("PAUSE");
			
		populate_and_display_grid(people_detail, tracking);// makes and displays the position of all people on a particular day
		
	}
	
	total_infection(initial_infection_num, num_of_days ,daily_infection_rate);//adds up all the infection by day and gives the number of infected people per day
	
	system("Pause");
	infection_simulation(tracking, num_of_days);//simulates the movement of all the people for total number of days
	
	return 0;

}
//gives total infected people number out of number of people
void total_infection(int initial_num, int num_of_days,int daily_infection_rate[]) {
	for (int i = 0; i < num_of_days; i++)
		initial_num += daily_infection_rate[i];
	cout << "Total infection: " << initial_num <<" out of "<<MAX_PEOPLE<< " People" << endl << endl;
}
//simulates the movement of people across the total number of days
void infection_simulation(char tracking[][GRID_SIZE],int num_of_days) {

	const int time_delay1 = 100;
	const int time_delay2 = 3;
	cout << "Full " << num_of_days << " days Simulation" << endl;

	for (int k = 0; k <= num_of_days; k++) {

		for (int i = 0; i < GRID_SIZE; i++) {
			
			for(int j = 0; j < GRID_SIZE; j++ ) {
				cout << tracking[i][j];
				sleep_for(nanoseconds(TIME_SLEEP));
				sleep_until(system_clock::now() + nanoseconds(time_delay1));//slows the output speed on the console screen , otherwise some lines are not printed while the program is being outputed
			}
			cout << endl;

		}
		sleep_for(nanoseconds(TIME_SLEEP));
		sleep_until(system_clock::now() + seconds(time_delay2));//does the same
		system("cls");
	}
}

void populate_and_display_grid(Person people[],char tracking[][GRID_SIZE]) {
	
	const int position_correction = 100;
	// Creates a 2D grid and populate it with "*" to represent location
	char grid[GRID_SIZE][GRID_SIZE];
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			grid[i][j] = '*';
		}
	}
	int count = 0;
	// Map array values to grid and populate with "@" for healthy person and 'T' for infected perosn
	for (int i = 0; i < MAX_PEOPLE; ++i) {
		int mapped_x = people[i].point_x + position_correction;  // Map x-coordinate to grid row index
		int mapped_y = people[i].point_y + position_correction;  // Map y-coordinate to grid column index

		if (people[i].get_infection() == true)
			grid[mapped_x][mapped_y] = 'T';//infected person
		else
			grid[mapped_x][mapped_y] = '@';//healthy person
		count++;
	}

	// Print the grid
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			tracking[i][j] = grid[i][j];
			cout << grid[i][j];
		}
		cout << endl;
	}
	//pauses the output so the grid output can be read and then eased
	system("Pause");
	system("cls");
	cout << endl;
}

void generate_id(Person  people[], string number_array[]) {
	
	string filler;
	int increment = 0;
	const int digit1_size = 2;
	const int digit2_size = 10;
	const int digit3_size = 10;
	const int time_delay = 900;
	int* increptr= &increment;
	
	//the inner most for loop sets the first number from right side, middle loop sets the middle number and the outer most loop sets the last number from right side
	for (int s = 1; s < digit1_size; s++) {// the outer range will need to be changed if max people increseas
		for (int t = 0; t < digit2_size; t++) {
			for (int u = 0; u < digit3_size; u++) {

				filler =  number_array[s] + number_array[t] + number_array[u];// adds each number up by joining it to make one unique id
				people[increment].set_id(filler);
				sleep_for(nanoseconds(TIME_SLEEP));
				sleep_until(system_clock::now() + nanoseconds(time_delay));
				*increptr += 1;
				filler = "";
			}
		}
	}
}

void location_and_infection(Person  people[], int &initial_infection_num) {

	for (int i = 0; i < MAX_PEOPLE; i++) {
		// randomly sets a persons x and y postion on the plane
		people[i].point_x = generate_rand_num(MAX_PLANE_SIZE, MIN_PLANE_SIZE);
		people[i].point_y = generate_rand_num(MAX_PLANE_SIZE, MIN_PLANE_SIZE);
	}
	
	const int MIN_INDEX = 0;
	const int MAX_INDEX = 99;
	int j = 0;
	int num = 0;
	//rondomly makes certain percent of the location infected
	while (j < INITIAL_INFECTION_RATE) {
		num = generate_rand_num(MAX_INDEX, MIN_INDEX);

		if (people[num].get_infection() == false) {

			people[num].set_infection(true);
			j++;	
		}
		initial_infection_num = j;
	}

}
//if a person starts moving out of the -100 to 100 boundary then this function prevents it from moving out by reversing the shift
void correction_by_boundary(Person people[], int index,int &shift_x, int &shift_y) {

	if (people[index].point_x > MAX_PLANE_SIZE){
		people[index].point_x--;
		shift_x--;
	}
	
	else if (people[index].point_x < MIN_PLANE_SIZE){
		people[index].point_x++;
		shift_x++;
	}
	
	if (people[index].point_y > MAX_PLANE_SIZE){
		people[index].point_y--;
		shift_y--;
	}
	
	else if (people[index].point_y < MIN_PLANE_SIZE){
		people[index].point_y++;
		shift_y++;
	}
		
}
//prints day number and the respective headings
void print_header(int j) {
	cout << "Day : " << j + 1 << endl << endl;
	cout << "ID " << setw(WIDTH_SPACE2) << "location " << setw(WIDTH_SPACE3) << "Infection Statues " << setw(WIDTH_SPACE1) << "X Movement " << setw(WIDTH_SPACE1) << "Y Movement " << endl;
	cout << "-----------------------------------------------------------------------------------------------------"<<endl;
}
//prints the persons details such as id, location on plane and x and y shift for that particular day
void print_details(Person people[], int shift_x, int shift_y, int index) {
		
	const int time_delay = 700;
	cout << people[index].get_id() << setw(WIDTH_SPACE4) << "(" << people[index].point_x << " ," << people[index].point_y << ")"<< "		"<< setw(WIDTH_SPACE4) << infection_status(people,index) << setw(WIDTH_SPACE1) << shift_x << setw(WIDTH_SPACE1) << shift_y << endl;
	sleep_for(nanoseconds(TIME_SLEEP));
	sleep_until(system_clock::now() + nanoseconds(time_delay));
	
}
//converts boolean info (0 and 1) to user readable info 
string infection_status(Person people[], int index) {

	if (people[index].get_infection() == true)
		return "Infected";
	else
		return "healthy";
}
//generates a random number between the certain range
int generate_rand_num(int max, int min) {

	
	return (rand() % (1 + max - min) + min);
}
//checks if a person has another person is nearby that might be infected
bool nearby_infected_element(int target_x, int target_y, bool target, Person array[], int size1, int index) {
	
	Person targetPerson;
	bool not_infected  = !targetPerson.get_infection();
	bool infected = false;
	for (int i = 0; i < size1; ++i) {
		if (i != index && target == false) { // Skip the index
			if ((target_x == array[i].point_x || target_x == array[i].point_x + 1 || target_x == array[i].point_x - 1) && (target_y == array[i].point_y || target_y == array[i].point_y + 1 || target_y == array[i].point_y - 1)  &&  array[i].get_infection() == true) {
				infected = true; // Match found in array_x
			}
		}
	}
	return (infected && not_infected);
	 
}