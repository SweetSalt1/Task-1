#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "Task.h"

class TaskManager {
private:
	std::vector<Employee*> employees;
	std::vector<Task*> tasks;
	int current_day;
public:
	TaskManager();
	void save_file();
	void load_file();

	const std::vector<Employee*>& get_all_employees();
	const std::vector<Task*>& get_all_tasks();

	void add_employee(Employee* employee);
	void remove_employee(Employee* employee);
	void search_employee(Employee* employee);

	void add_task(Task* task);
	void remove_task(Task* task);
	void search_task(int id);

	void assign_task_to_employee(Task* task, Employee* employee);

	void see_employment(Employee* employee);

	void see_status();

	void task_ready();

	void end_day();
	void timeskip();

	void show_all_employment();
};
