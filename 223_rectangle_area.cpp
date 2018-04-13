class Solution {
public:
    void intersect_line(int A, int B, int C, int D, int& E, int& F) {
        if (B <= C) {
            E = F = 0;
        } else if (B > C && C >= A) {
            E = C;
            F = (D > B ? B : D);
        } else {
            E = A;
            if (D > B) {
                F = B;
            } else if (D <= B && D > A) {
                F = D;
            } else {
                E = F = 0;
            }
        }
    }
    
    void intersect_rect(int A, int B, int C, int D, int E, int F, int G, int H, int& W, int& X, int& Y, int& Z) {
        intersect_line(A, C, E, G, W, Y);
        intersect_line(B, D, F, H, X, Z);
    }
    
    int area(int A, int B, int C, int D) {
        return (C - A) * (D - B);
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int W = 0, X = 0, Y = 0, Z = 0;
        intersect_rect(A, B, C, D, E, F, G, H, W, X, Y, Z);
        return area(A, B, C, D) + area(E, F, G, H) - area(W, X, Y, Z); 
    }
};