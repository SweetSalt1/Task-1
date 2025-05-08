#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "Tasdk.h"

class TaskManager {
private:
	std::vector<Employee*> employees;
	std::vector<Task*> tasks;
	int current_day;
public:
	TaskManager();
	void add_employee(Employee* employee);
	void remove_employee(Employee* employee);
	void search_employee(Employee* employee);

	void add_task(Task* task);
	void remove_task(Task* task);
	void search_task(Task* task);

	void assign_task_to_employee(Task* task, Employee* employee);

	void see_employment(Employee* employee);

	void see_status();

	void task_ready();						// ФОРМУЛА: готовность = трудоемкость - 7 * часы работника в день  (_status изменяется)

	void end_day();							// + 1 день и -1 день из дедлайна, если дедлайн < 0, то задача просрочена. Пользователь самостоятельно вызывает соответствующую комканду.
	void timeskip();						// функция вызывает функцию end_day столько раз, сколько нужно пользователю.
};