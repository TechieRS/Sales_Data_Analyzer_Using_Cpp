#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define FILENAME "sales_data.bin"

struct SaleRecord {
    int id;
    char item[30];
    float amount;
};

void importSalesData();
void calculateMetrics();
void generateReport();

int main() {
    int choice;
    do {
        cout << "\nSales Data Analyzer\n";
        cout << "1. Import Sales Data\n";
        cout << "2. Calculate Metrics\n";
        cout << "3. Generate Report\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: importSalesData(); break;
            case 2: calculateMetrics(); break;
            case 3: generateReport(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}

void importSalesData() {
    ofstream file(FILENAME, ios::app | ios::binary);
    if (!file) {
        cerr << "Error opening file" << endl;
        return;
    }

    SaleRecord record;
    int n;

    cout << "Enter the number of sales records to import: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter details for record " << i + 1 << ":\n";
        cout << "Sale ID: ";
        cin >> record.id;
        cin.ignore();
        cout << "Item Name: ";
        cin.getline(record.item, 30);
        cout << "Sale Amount: ";
        cin >> record.amount;

        file.write(reinterpret_cast<char*>(&record), sizeof(SaleRecord));
    }

    file.close();
    cout << "Sales data imported successfully!\n";
}

void calculateMetrics() {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        cerr << "Error opening file" << endl;
        return;
    }

    SaleRecord record;
    float totalSales = 0.0;
    int count = 0;

    while (file.read(reinterpret_cast<char*>(&record), sizeof(SaleRecord))) {
        totalSales += record.amount;
        count++;
    }

    file.close();

    if (count > 0) {
        cout << "\nMetrics:\n";
        cout << "Total Sales: " << fixed << setprecision(2) << totalSales << endl;
        cout << "Average Sales: " << totalSales / count << endl;
    } else {
        cout << "No sales data available.\n";
    }
}

void generateReport() {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        cerr << "Error opening file" << endl;
        return;
    }

    SaleRecord record;

    cout << "\nSales Report:\n";
    cout << "ID\tItem Name\t\tAmount\n";
    cout << "--------------------------------------\n";

    while (file.read(reinterpret_cast<char*>(&record), sizeof(SaleRecord))) {
        cout << record.id << "\t" << left << setw(15) << record.item << "\t" << fixed << setprecision(2) << record.amount << endl;
    }

    file.close();
    cout << "--------------------------------------\n";
    cout << "End of Report.\n";
}