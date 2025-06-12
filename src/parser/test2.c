int main() {
    int i;
    i = 0;

    while (i < 10) {
        if (i == 3) {
            i = i + 1;
            continue;
        } else if (i == 7) {
            break;
        } else {
            i = i + 2;
        }
    }

    return i;
}
