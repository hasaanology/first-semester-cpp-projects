//Cargo clearance system:

#include <iostream>
#include <string>
using namespace std;

int main() {
int weight_category, origin_category, dest_category, res_items,
doc_status, insp_status, insur_status, importer_type, priority_lev, isCustomFlag;
double ship_decValue;
string clearance_status;

cout << "Enter documentation status: (1=Complete, 0=Incomplete): ";
if (!(cin >> doc_status) || doc_status < 0 || doc_status > 1) {
  cout << "Invalid input. Please enter 0 or 1." << endl;
  return 0;
}

if (doc_status == 0) {
  int temp_clearance;
  cout << "Is temporary clearance allowed? (1=Yes, 0=No): ";
  if (!(cin >> temp_clearance) || temp_clearance < 0 || temp_clearance > 1) {
    cout << "Invalid input. Please enter 0 or 1." << endl;
    return 0;
  }

  if (temp_clearance == 1) {
    clearance_status = "TEMPORARY CLEARANCE GRANTED";
  } else {
    clearance_status = "REJECTED: Incomplete documentation";
  }
} else {
  cout << "Enter origin category (1=Domestic, 2=Standard Foreign. 3=High-Risk Region): ";
  if (!(cin >> origin_category) || origin_category < 1 || origin_category > 3) {
    cout << "Invalid input. Please enter a value between 1 and 3." << endl;
    return 0;
  }

  cout << "Enter importer type: (1=Individual, 2=Authorized Commercial) ";
  if (!(cin >> importer_type) || importer_type < 1 || importer_type > 2) {
    cout << "Invalid input. Please enter 1 or 2." << endl;
    return 0;
  }

  int add_verification;
  bool stage2_passed;
  if (origin_category == 3 && importer_type == 1) {
    cout << "Additional verification passes? (1=Yes, 0=No): ";
    if (!(cin >> add_verification) || add_verification < 0 || add_verification > 1) {
      cout << "Invalid input. Please enter 0 or 1." << endl;
      return 0;
    }

    if (add_verification == 1) {
      stage2_passed = 1;
    } else {
      stage2_passed = 0;
    }
  } else {
    stage2_passed = 1;
  }

  if (stage2_passed == 0) {
    clearance_status = "REJECTED: FAILED SECURITY VERIFICATION";
  } else {
    bool stage3_passed;
    cout << "Enter shipment's declared value: ";
    if (!(cin >> ship_decValue) || ship_decValue < 0) {
      cout << "Invalid input. Declared value must be non-negative." << endl;
      return 0;
    }

    if (ship_decValue > 50000) {
      cout << "Enter inspection status: (1=Passed, 0=Failed): ";
      if (!(cin >> insp_status) || insp_status < 0 || insp_status > 1) {
        cout << "Invalid input. Please enter 0 or 1." << endl;
        return 0;
      }

      if (insp_status == 0) {
        stage3_passed = 0;
      } else {
        stage3_passed = 1;
      }
    } else {
      stage3_passed = 1;
    }

    if (stage3_passed == 0) {
      clearance_status = "REJECTION: Financial inspection failed";
    } else {
      bool stage4_passed;
      cout << "Enter weight category (1=Light, 2=Medium, 3=Heavy, 4=Very Heavy): ";
      if (!(cin >> weight_category) || weight_category < 1 || weight_category > 4) {
        cout << "Invalid input. Please enter a value between 1 and 4." << endl;
        return 0;
      }

      if (weight_category == 4) {
        int add_checks;
        cout << "Additional checks verified? (1=Yes, 0=No): ";
        if (!(cin >> add_checks) || add_checks < 0 || add_checks > 1) {
          cout << "Invalid input. Please enter 0 or 1." << endl;
          return 0;
        }

        if (add_checks == 1) {
          stage4_passed = 1;
        } else {
          stage4_passed = 0;
        }
      } else {
        stage4_passed = 1;
      }

      if (stage4_passed == 0) {
        clearance_status = "REJECTED: Physical inspection failed";
      } else {
        bool stage5_passed;
        cout << "Enter number of restricted items: ";
        if (!(cin >> res_items) || res_items < 0) {
          cout << "Invalid input. Restricted items must be non-negative." << endl;
          return 0;
        }

        cout << "Enter destination category (1=Normal, Sensitive=2): ";
        if (!(cin >> dest_category) || dest_category < 1 || dest_category > 2) {
          cout << "Invalid input. Please enter 1 or 2." << endl;
          return 0;
        }

        if (res_items > 3 && dest_category == 2) {
          stage5_passed = 0;
        } else {
          if (res_items > 5 && dest_category == 1) {
            stage5_passed = 0;
          } else {
            stage5_passed = 1;
          }
        }

        if (stage5_passed == 0) {
          clearance_status = "REJECTED: Restricted items exceded for zone.";
        } else {
          cout << "Enter insurance status: (1=Insured, 0=Uninsured) ";
          if (!(cin >> insur_status) || insur_status < 0 || insur_status > 1) {
            cout << "Invalid input. Please enter 0 or 1." << endl;
            return 0;
          }

          cout << "Is shipment previously flagged by customs? (Yes=1, No=0) ";
          if (!(cin >> isCustomFlag) || isCustomFlag < 0 || isCustomFlag > 1) {
            cout << "Invalid input. Please enter 0 or 1." << endl;
            return 0;
          }

          if (isCustomFlag == 1) {
            clearance_status = "MANUAL REVIEW REQUIRED";
          } else {
            if (insur_status == 0 && ship_decValue > 10000) {
              clearance_status = "MANUAL REVIEW REQUIRED";
            } else {
              cout << "Enter priority level:(1=Standard, 2=High Priority) ";
              if (!(cin >> priority_lev) || priority_lev < 1 || priority_lev > 2) {
                cout << "Invalid input. Please enter 1 or 2." << endl;
                return 0;
              }

              if (priority_lev == 2) {
                clearance_status = "PRIORITY CLEARED FOR WAREHOUSE";
              } else {
                clearance_status = "CLEARED FOR WAREHOUSE";
              }
            }
          }
        }
      }
    }
  }
}

cout << "Clearance status: " << clearance_status;
return 0;
}

