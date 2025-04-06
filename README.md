# Sales Data Analyzer (C++)

This is a simple console-based **Sales Data Analyzer** built in C++. It allows users to import sales records, calculate total and average sales, and generate a neat sales report. All data is stored in a binary file (`sales_data.bin`) for persistent storage.

## Features

- Import sales records (ID, item name, and amount)
- Calculate total and average sales from saved data
- Generate a formatted sales report
- Stores data in binary format for efficiency

## File Structure

- `main.cpp`: Contains all program logic
- `sales_data.bin`: Binary file used to store sales records

## How to Compile and Run

### On Windows (using g++)

```bash
g++ main.cpp -o sales_analyzer
sales_analyzer
```

### On Linux/Mac

```bash
g++ main.cpp -o sales_analyzer
./sales_analyzer
```

## Menu Options

When you run the program, you’ll be presented with a menu:

```
Sales Data Analyzer
1. Import Sales Data
2. Calculate Metrics
3. Generate Report
4. Exit
Enter your choice:
```

## Example

**Input:**

```
Enter the number of sales records to import: 2

Enter details for record 1:
Sale ID: 101
Item Name: Pen
Sale Amount: 15.5

Enter details for record 2:
Sale ID: 102
Item Name: Notebook
Sale Amount: 50.0
```

**Output (Metrics):**

```
Metrics:
Total Sales: 65.50
Average Sales: 32.75
```

**Output (Report):**

```
Sales Report:
ID	Item Name		Amount
--------------------------------------
101	Pen            	15.50
102	Notebook       	50.00
--------------------------------------
End of Report.
```

## Notes

- The binary file (`sales_data.bin`) is created/updated automatically.
- `cin.ignore()` is used to properly handle input buffer after reading integers.
- Output is formatted using `iomanip`.

## License

This project is open source and available under the [MIT License](LICENSE).
