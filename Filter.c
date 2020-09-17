#include <iostream>
#include "Matrix.c"
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* From here to */

matrix * A;
matrix * B;
matrix * state;
matrix * lastState;
matrix * C;
matrix * Q;
matrix * R;
matrix * y;
matrix * x;
x = newMatrix(3, 1);
matrix * K;
K = newMatrix(3, 3);
matrix * action;
action = newMatrix(3, 1);
matrix * measurement;
measurement = newMatrix(3, 1);
matrix * P;
P = newMatrix(3, 3);
matrix * p;
p = newMatrix(3, 3);
float tau1, tau2, tau3;
float m_pitch, m_roll, m_yaw;
float pitch, roll, yaw;
float new_pitch, new_roll, new_yaw;

/* here is all just declaration (globally) of our arrays and floats and things
    that we'll be using for our calculations.   */


/*
    Method: initKalman
    input: null
    return: void
    Description: Initializes each matrix and assigns values to known quantities
*/

void initKalman() {
    A = newMatrix(3, 3);
    B = newMatrix(3, 3);
    state = newMatrix(3, 1);
    lastState = newMatrix(3, 1);
    C = newMatrix(3, 3);
    Q = newMatrix(3, 3);
    R = newMatrix(3, 3);
    y = newMatrix(3, 1);


    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            setElement(A, i, j, 0);
        }
    }
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            setElement(B, i, j, 0);
        }
    }

    setElement(state, 1, 1, 0);
    setElement(state, 2, 1, 0);
    setElement(state, 3, 1, 0);


    lastState = copyMatrix(state);
}

/*
    Method: kalman
    input: null
    return: void
    Description: Implementation for the actual Kalman algorithm with predict
        and update equations
*/
void kalman() {
    lastState = copyMatrix(state);
    setElement(state, 1, 1, pitch);
    setElement(state, 2, 1, roll);
    setElement(state, 3, 1, yaw);

    setElement(measurement, 1, 1, m_pitch);
    setElement(measurement, 2, 1, m_roll);
    setElement(measurement, 3, 1, m_yaw);

    setElement(action, 1, 1, tau1);
    setElement(action, 2, 1, tau2);
    setElement(action, 3, 1, tau3);


    /* Let's predict! */

    //These are intermediate or 'temp' matrices for calculating
    //  what we actually want
    matrix * a_ls;
    a_ls = newMatrix(3, 1);
    matrix * b_action;
    b_action = newMatrix(3, 1);
    matrix * a_p;
    a_p = newMatrix(3, 1);
    matrix * a_tran;
    a_tran = newMatrix(3, 1);
    matrix * apa_tran;
    apa_tran = newMatrix(3, 1);


    //This part is representative of:
    //  x = A * lastState + B * action
    product(A, lastState, a_ls);
    product(B, action, b_action);
    sum(a_ls, b_action, x);

    //This part is representative of:
    //  p = A * P * A' + Q
    product(A, P, a_p);
    transpose(A, a_tran);
    product(a_p, a_tran, apa_tran);
    sum(apa_tran, Q, p);

    //Allow me to just clean this up...
    deleteMatrix(a_ls);
    deleteMatrix(b_action);
    deleteMatrix(a_p);
    deleteMatrix(a_tran);
    deleteMatrix(apa_tran);


    /* Let's Update! */
    
    matrix * p_trans;
    p_trans = newMatrix(3, 3);
    matrix * pC;
    pC = newMatrix(3, 3);
    matrix * pCp;
    pCp = newMatrix(3, 3);
    matrix * Cp;
    Cp = newMatrix(3, 3);
    matrix * C_trans;
    C_trans = newMatrix(3, 3);
    matrix * CpC;
    CpC = newMatrix(3, 3);
    matrix * CpCR;
    CpCR = newMatrix(3, 3);
    matrix * Clast;
    Clast = newMatrix(3, 1);
    matrix * ysub;
    ysub = newMatrix(3, 1);
    matrix * Kysub;
    Kysub = newMatrix(3, 1);
    matrix * id;
    id = newMatrix(3, 3);
    matrix * KC;
    KC = newMatrix(3, 1);
    matrix * idsub;
    idsub = newMatrix(3, 3);

    //This part is representative of:
    //  p * C * p'
    product(p, C, pC);
    transpose(p, p_trans);
    product(pC, p_trans, pCp);
    
    //This part is representative of:
    //  (C*p*C' + R)
    product(C, p, Cp);
    transpose(C, C_trans);
    product(Cp, C_trans, CpC);
    sum(CpC, R, CpCR);
    
    //Product of the above matrices:
    product(pCp, CpCR, K);
    
    //y = C*state
    product(C, state, y);
    
    //state = x + K*(y-C*lastState)
    product(C, lastState, Clast);
    difference(y, Clast, ysub);
    product(K, ysub, Kysub);
    sum(x, Kysub, state);
    
    //P = (eye(3) - K*C)*p
    identity(id);
    product(K, C, KC);
    difference(id, KC, idsub);
    product(idsub, p, x);
}


int main() {

}
