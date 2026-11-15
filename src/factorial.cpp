#include <random>

int random(int flips, int trials, int probability) {
    if (probability <= 0) return 0;
    int tracker = 0;
    int heads = 0;
    int tails = 0;
    int running_heads = 0;

    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 100);

    const int prob = std::clamp(probability, 0, 100);

    while (tracker < trials) {
        for (int i = 0; i < flips; ++i) {
            if (distribution(generator) <= prob) {
                ++heads;
            } else {
                ++tails;
            }
        }
        running_heads += heads;
        heads = 0;
        ++tracker;
    }

    return running_heads / trials;
}


