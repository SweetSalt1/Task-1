#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Task.h"
/**
 * @brief Класс, представляющий сотрудника.
 */

class Employee {
private:
	std::string _name;				///< Имя сотрудника
	int _hours_in_day;				///< Доступные часы в день
	std::vector<Task*> _tasks;		///< Список назначенных задач
public:
	/**
	* @brief Конструктор сотрудника.
	* @param name Имя сотрудника
	* @param hours_in_week Количество доступных часов в неделю
	*/
	Employee(const std::string& name, int hours_in_day);
	/**
	 * @brief Назначить задачу сотруднику.
	 * @param task Указатель на задачу
	 */
	void assign_task(Task* task);
	/**
	 * @brief Удалить задачу у сотрудника.
	 * @param task Указатель на задачу
	 */
	void remove_task(Task* task);

	/**
	 * @brief Получить имя сотрудника.
	 * @return Ссылка на строку с именем
	 */
	const std::string& get_name() const;
	/**
	 * @brief Получить доступные часы в день.
	 * @return Количество часов
	 */
	int get_hours_in_day();
	/**
	 * @brief Получить список задач.
	 * @return Вектор указателей на задачи
	 */
	const std::vector<Task*>& get_tasks() const;

	/**
	 * @brief Проверить доступность сотрудника.
	 * @return true, если сотрудник доступен
	 */
	bool is_available() const;
	/**
	 * @brief Подсчитать общее количество часов всех задач.
	 * @return Сумма часов
	 */
	int total_assigned_hours() const;
};
