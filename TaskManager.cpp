#include "TaskManager.h"
using namespace std;
TaskManager::TaskManager(): current_day(0) {}

void TaskManager::save_file() {
	ofstream out("baze.txt");
	if (!out.is_open()) {
		cout << "Ошибка открытия файла для записи." << endl;
		return;
	}
	// Записываем сотрудников в бд.
	out << employees.size() << endl;
	for (Employee* emp : employees) {
		out << emp->get_name() << " " << emp->get_hours_in_day() << endl;
	}
	// Записываем задачи в бд.
	out << tasks.size() << endl;
	for (Task* task : tasks) {
		out << task->get_id() << " ";
		out << task->get_description() << " ";
		out << task->get_workload_hours() << " ";
		out << task->get_remaining_workload() << " ";
		out << task->get_deadline_days() << " ";
		out << task->get_status() << " ";
		if (task->get_assigned_employee())
			out << task->get_assigned_employee()->get_name() << endl;
		else {
			out << "NONE" << endl;
		}
	}
	out.close();
}
void TaskManager::load_file() {
	ifstream in("baze.txt");
	if (!in.is_open()) {
		cout << "Ошибка открытия файла для чтения." << endl;
		return;
	}

	size_t emp_count;
	if (!(in >> emp_count)) {
		cout << "Файл пустой или поврежден (работники)." << endl;
		return;
	}
	in.ignore();

	employees.clear();
	tasks.clear();

	for (size_t i = 0; i < emp_count; ++i) {
		string name;
		int hours;
		in >> name >> hours;
		in.ignore();
		employees.push_back(new Employee(name, hours));
	}

	size_t task_count;
	if (!(in >> task_count)) {
		cout << "Файл пуст или поврежден (задачи)." << endl;
		return;
	}
	in.ignore();

	for (size_t i = 0; i < task_count; ++i) {
		int id;
		string desc;
		int hours, rem_hours, days;
		int status;
		string emp_name;

		if (!(in >> id >> desc >> hours >> rem_hours >> days >> status >> emp_name))
		{
			std::cout << "Ошибка формата задачи на строке " << (i + 1) << std::endl;
			break;
		}
		in.ignore();

		Employee* assigned = nullptr;
		if (emp_name != "NONE") {
			for (Employee* e : employees) {
				if (e->get_name() == emp_name) {
					assigned = e;
					break;
				}
			}
		}

		Task* t = new Task(id, desc, hours, days, status, assigned);
		tasks.push_back(t);
		if (assigned)
			assigned->assign_task(t);
	}
	in.close();
}

const std::vector<Employee*>& TaskManager::get_all_employees() { return employees; }
const std::vector<Task*>& TaskManager::get_all_tasks() { return tasks; }

void TaskManager::add_employee(Employee* employee) {
	if (employee != nullptr) {
		employees.push_back(employee);
		cout << "Сотрудник " << employee->get_name() << " добавлен." << endl;
	}
}

void TaskManager::remove_employee(Employee* employee) {
	if (employee == nullptr) {
		cout << "Ошибка удаления." << endl;
		return;
	}

	for (Task* task : tasks) {
		if (task != nullptr && task->get_assigned_employee() == employee) {
			task->set_assigned_employee(nullptr);
			employee->remove_task(task);
			cout << "Задача откреплена." << endl;
		}
	}


	for (size_t i = 0; i < employees.size(); i++) {
		if (employees[i] == employee) {
			employees.erase(employees.begin() + i);
			cout << "Сотрудник " << employee->get_name() << " удален." << endl;
			delete employee;
			return;
		}
	}
	cout << "Сотрудник не найден." << endl;
}

void TaskManager::search_employee(Employee* employee) {
	if (employee == nullptr) {
		cout << "Ошибка" << endl;
		return;
	}
	for (Employee* emp : employees) {
		if (emp == employee)
		{
			cout << " Информация о сотруднике" << endl;
			cout << "Имя: " << emp->get_name() << endl;
			cout << "Доступные часы в день: " << emp->get_hours_in_day() << endl;
			cout << "Назначено задач: " << emp->get_tasks().size() << endl;
			cout << "Занято часов: " << emp->total_assigned_hours() << endl;
			return;
		}
	}
	cout << "Сотрудник не найден" << endl;
}

void TaskManager::add_task(Task* task) {
	if (task != nullptr) {
		tasks.push_back(task);
		cout << "Задача " << task->get_id() << " добавлена." << endl;
	}
};
void TaskManager::remove_task(Task* task) {
	if (!task) {
		cout << "Ошибка: задача не найдена." << endl;
		return;
	}
	Employee* emp = task->get_assigned_employee();
	if (emp) {
		emp->remove_task(task);
		task->set_assigned_employee(nullptr);
	}
	for (size_t i = 0; i < tasks.size(); ++i) {
		if (tasks[i] == task) {
			cout << "Описание: " << task->get_description() << endl;
			tasks.erase(tasks.begin() + i);
			cout << "Задача удалена." << endl;
			return;
		}
	}
	cout << "Задача не найдена." << endl;
};
void TaskManager::search_task(int id) {
	for (Task* task : tasks) {
		if (task->get_id() == id) {
			cout << "Задача найдена: " << endl;
			cout << "ID: " << task->get_id() << endl;
			cout << "Описание: " << task->get_description() << endl;
			cout << "Часы: " << task->get_workload_hours() << endl;
			cout << "Дедлайн: " << task->get_deadline_days() << endl;
			std::string status;
			switch (task->get_status()) {
			case 0: status = "Не готово"; break;
			case 1: status = "Просрочено"; break;
			case 2: status = "Готово"; break;
			default: status = "Неизвестно"; break;
			}
			cout << "Статус: " << status << endl;
			return;
		}
	}
	cout << "Задача с таким ID не найдена." << endl;
};

void TaskManager::assign_task_to_employee(Task* task, Employee* employee) {
	if (task && employee)
		employee->assign_task(task);
}

void TaskManager::see_employment(Employee* employee) {
	if (employee->get_tasks().empty()) {
		cout << "Работник свободен." << endl;
	}
	else {
		cout << "Работник занят." << endl;
	}
}

void TaskManager::see_status() {
	for (Task* task : tasks) {
		std::string status;
		switch (task->get_status()) {
		case 0: { 
			status = "Не готово."; 
			break; 
		}
		case 1: { 
			status = "Просрочено."; 
			break; 
		}
		case 2: { 
			status = "Готово."; 
			break; 
		}
		default: { 
			status = "Неизвестно."; 
			break; 
		}
		}
		std::cout << "ID: " << task->get_id() << ", Описание: " << task->get_description() << ", Статус: " << status << std::endl;
	}
}

void TaskManager::task_ready() {
	for (Employee* emp : employees) {
		auto emp_tasks = emp->get_tasks();
		if (emp_tasks.empty()) continue;

		int hours_per_task = emp->get_hours_in_day() / emp_tasks.size();

		for (Task* task : emp_tasks) {
			task->reduce_workload(hours_per_task);

			if (task->get_remaining_workload() <= 0) {
				task->set_status(2);  // Готово
			}
			else if (task->get_deadline_days() < 0) {
				task->set_status(1);  // Просрочено
			}
			else {
				task->set_status(0);  // Не готово
			}
		}
	}
}

void TaskManager::end_day() {
	current_day++;
	for (Task* task : tasks) {
		task->get_deadline_days()--;
	}
	task_ready();
}

void TaskManager::timeskip() {
	int days;
	cout << "Введите колличество дней, которые надо пропустить: ";
	cin >> days;
	for (int i = 0; i < days; i++) {
		end_day();
	}
}

void TaskManager::show_all_employment() {
	if (employees.empty()) {
		std::cout << "Список сотрудников пуст.\n";
		return;
	}

	for (Employee* e : employees) {
		std::cout << "Сотрудник: " << e->get_name() << std::endl;
		const auto& tasks = e->get_tasks();
		if (tasks.empty()) {
			std::cout << "  - Свободен\n";
		}
		else {
			std::cout << "  - Занят задачами:\n";
			for (Task* task : tasks) {
				std::cout << "      • Задача ID " << task->get_id()
					<< ": " << task->get_description() << std::endl;
			}
		}
	}
}
