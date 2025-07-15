# C++ Payroll System

This is a simple C++ program that simulates a basic **payroll system** using classes. It calculates regular and overtime pay based on working hours.

## 🧠 Features

- Class-based design (`Employee`)
- Calculates:
  - Regular pay
  - Overtime pay
  - Weekly salary breakdown
- Uses `min()` and `max()` logic for hour calculation

## 🧮 Variables Used

| Variable     | Description                                           |
|--------------|-------------------------------------------------------|
| `name`       | Employee name (string)                                |
| `id`         | Employee ID (int)                                     |
| `dept`       | Department name (string)                              |
| `salary`     | Monthly salary (double)                               |
| `hours`      | Total hours worked in a week (double)                 |
| `bonus`      | Bonus added (double, default = 0.0)                   |
| `weekly`     | Weekly salary = salary / 4                            |
| `rate`       | Hourly rate = weekly / 40                             |
| `reg`        | Regular pay = min(hours, 40) * rate                   |
| `ot`         | Overtime pay = max(hours - 40, 0) * rate * 1.5        |

## 🏁 How to Run

1. Compile using any C++ compiler:
2. Run the executable:
## 📌 Notes

- This is a basic model and doesn't handle input/output or multiple employees yet.
- Ideal for learning how classes and functions work in C++.

## 📄 License

This project is open-source and free to use.