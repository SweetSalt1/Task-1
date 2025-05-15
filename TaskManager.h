#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "Task.h"

/**
 * @brief Класс управления задачами и сотрудниками.
 */

class TaskManager {
private:
	std::vector<Employee*> employees;	///< Список сотрудников
	std::vector<Task*> tasks;			///< Список задач
	int current_day;					///< Текущий день (для дедлайнов)
public:
	/**
	 * @brief Конструктор по умолчанию.
	 */
	TaskManager();
	/**
	 * @brief Сохраняет текущие данные в файл.
	 */
	void save_file();
	/**
	 * @brief Загружает данные из файла.
	 */
	void load_file();

	/**
	* @brief Возвращает список всех сотрудников.
	* @return Ссылка на вектор сотрудников.
	*/
	const std::vector<Employee*>& get_all_employees();
	/**
	 * @brief Возвращает список всех задач.
	 * @return Ссылка на вектор сотрудников.
	 */
	const std::vector<Task*>& get_all_tasks();

	/**
	 * @brief Добавляет сотрудника в систему (список).
	* @param employee Указатель на добавляемого сотрудника.
	 */
	void add_employee(Employee* employee);
	/**
	 * @brief Удаляет сотрудника из системы (списка).
	 * @param employee Указатель на удаляемого сотрудника.
	 */
	void remove_employee(Employee* employee);
	/**
	 * @brief Ищет сотрудника в системе (списке).
	 * @param employee Указатель на искомого сотрудника.
	 */
	void search_employee(Employee* employee);

	/**
	 * @brief Добавляет задачу в систему (список).
	 * @param task Указатель на добавляемую задачу.
	 */
	void add_task(Task* task);
	/**
	 * @brief Удаляет задачу из системы (списка).
	 * @param task Указатель на удаляемую задачу.
	 */
	void remove_task(Task* task);
	/**
	 * @brief Ищет задачу в системе (списке).
	 * @param task Указатель на искомую задачу.
	 */
	void search_task(int id);

	/**
	 * @brief Назначает задачу сотруднику.
	 * @param task Указатель на задачу.
	 * @param employee Указатель на сотрудника.
	 */
	void assign_task_to_employee(Task* task, Employee* employee);

	/**
	 * @brief Показывает занятость конкретного сотрудника.
	 */
	void see_employment(Employee* employee);

	/**
	 * @brief Показывает статус всех задач.
	 */
	void see_status();

	/**
	 * @brief Показывает статус всех задач.
	 */
	void task_ready();

	/**
	 * @brief Завершает текущий день, обновляя дедлайны и прогресс задач.
	 */
	void end_day();
	/**
	 * @brief Пропускает заданное количество дней.
	 */
	void timeskip();

	/**
	 * @brief Показывает занятость всех сотрудников.
	 */
	void show_all_employment();
};
