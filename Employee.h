#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Task.h"

class Employee {
private:
	std::string _name;
	int _hours_in_week;
	std::vector<Task*> _tasks;
public:
	Employee(const std::string name, int hours_in_week): _name(name), _hours_in_week(hours_in_week), _tasks();
	void assign_task(Task* task);
	void remove_task(Task* task);
};