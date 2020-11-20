#include <iostream>
#include <cmath>
using namespace std;

// Prototype
double getRho(int);
double getPv(int);

int main(void) {
  double RH, Ptot, Pv, Rho, mv;
  int T;
  int V = 1;
  char redo;

  do 
  {
    // Input
    cout << "\nTemperatur i hela grader (0-50): ";
    cin >> T;
    cout << "Fuktighet i hela procent (0-100): ";
    cin >> RH;
    cout << "Lufttryck i hela kPa (~101): ";
    cin >> Ptot;
  
    // Fixa enheter och avrunda
    Ptot = Ptot * 1000;
    T = 5 * round(T/5.0);
    RH = 5 * round(RH/5.0)/100;

    // Läs in data
    Rho = getRho(T);
    Pv = getPv(T);

    // Beräkning
    mv = 0.622 * Rho * V * (RH * Pv)/(Ptot - (RH * Pv));

    cout << "\nDetta motsvarar: " << mv*1000 << " gram vatten per kubikmeter." << endl;

    // Read if the user wants to redo
		cout << "Beräkna igen? (j/n): ";
		cin >> redo;

	}while (redo == 'J' || redo == 'j');

  return 0;
}

double getRho(int T) {
  double Rho;

  if (T == 0)
  {
    Rho = 1.292;
  } else if (T == 5)
  {
    Rho = 1.269;
  } else if (T == 10)
  {
    Rho = 1.246;
  } else if (T == 15)
  {
    Rho = 1.225;
  } else if (T == 20)
  {
    Rho = 1.204;
  } else if (T == 25)
  {
    Rho = 1.184;
  } else if (T == 30)
  {
    Rho = 1.164;
  }else if (T == 35)
  {
    Rho = 1.145;
  }else if (T == 40)
  {
    Rho = 1.127;
  } else if (T == 45)
  {
    Rho = 1.109;
  } else if (T == 50)
  {
    Rho = 1.092;
  }

  return Rho;
}

double getPv(int T) {
  double Pv;

    if (T == 0)
  {
    Pv = 611.3;
  } else if (T == 5)
  {
    Pv = 872.1;
  } else if (T == 10)
  {
    Pv = 1227.6;
  } else if (T == 15)
  {
    Pv = 1705.1;
  } else if (T == 20)
  {
    Pv = 2339;
  } else if (T == 25)
  {
    Pv = 3169;
  } else if (T == 30)
  {
    Pv = 4246;
  }else if (T == 35)
  {
    Pv = 5628;
  }else if (T == 40)
  {
    Pv = 7384;
  } else if (T == 45)
  {
    Pv = 9593;
  } else if (T == 50)
  {
    Pv = 12350;
  }

  return Pv;
}
