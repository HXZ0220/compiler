int main(void) {
    int x;
    x = 0;
    while (x < 3) {
        if (x == 1) {
            x = x + 2;
            continue;
        }
        x = x + 1;
        if (x == 3) {
            break;
        }
    }
    return x;
}
