#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

const int WIDTH = 1000;
const int HEIGHT = 600;
const int NUM_BARS = 80;
const int BAR_WIDTH = WIDTH / NUM_BARS;
int speed = 50; // Default speed

// Function to generate a random array
std::vector<int> generateRandomArray(int size, int maxHeight) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxHeight + 10;
    }
    return arr;
}

// Function to visualize sorting using SFML
void drawBars(sf::RenderWindow &window, const std::vector<int> &arr, int highlight1 = -1, int highlight2 = -1) {
    window.clear(sf::Color::Black);
    for (size_t i = 0; i < arr.size(); i++) {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH - 2, arr[i]));
        bar.setPosition(i * BAR_WIDTH, HEIGHT - arr[i]);

        if (i == highlight1 || i == highlight2) {
            bar.setFillColor(sf::Color::Red);
        } else {
            bar.setFillColor(sf::Color::White);
        }

        window.draw(bar);
    }
    window.display();
}

// Sleep function to control speed
void wait() {
    std::this_thread::sleep_for(std::chrono::milliseconds(speed));
}

// Sorting Algorithms

// 1. Bubble Sort
void bubbleSort(sf::RenderWindow &window, std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                drawBars(window, arr, j, j + 1);
                wait();
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(sf::RenderWindow &window, std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
        drawBars(window, arr, i, minIdx);
        wait();
    }
}

// 3. Insertion Sort
void insertionSort(sf::RenderWindow &window, std::vector<int> &arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            drawBars(window, arr, j, i);
            wait();
        }
        arr[j + 1] = key;
        drawBars(window, arr, j + 1, i);
        wait();
    }
}

// 4. Merge Sort (Recursive)
void merge(std::vector<int> &arr, int left, int mid, int right, sf::RenderWindow &window) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(arr.begin() + left, arr.begin() + left + n1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
        drawBars(window, arr, k - 1);
        wait();
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int> &arr, int left, int right, sf::RenderWindow &window) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, window);
        mergeSort(arr, mid + 1, right, window);
        merge(arr, left, mid, right, window);
    }
}

// 5. Quick Sort
int partition(std::vector<int> &arr, int low, int high, sf::RenderWindow &window) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
            drawBars(window, arr, i, j);
            wait();
        }
    }
    std::swap(arr[i + 1], arr[high]);
    drawBars(window, arr, i + 1, high);
    wait();
    return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high, sf::RenderWindow &window) {
    if (low < high) {
        int pi = partition(arr, low, high, window);
        quickSort(arr, low, pi - 1, window);
        quickSort(arr, pi + 1, high, window);
    }
}

int main() {
    srand(time(0));

    int choice;
    std::vector<int> arr = generateRandomArray(NUM_BARS, HEIGHT - 50);

    std::cout << "Choose Sorting Algorithm:\n";
    std::cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    std::cout << "Set Speed (10 - Fast, 100 - Slow): ";
    std::cin >> speed;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Visualizer");
    drawBars(window, arr);

    std::this_thread::sleep_for(std::chrono::seconds(1));

    switch (choice) {
        case 1: bubbleSort(window, arr); break;
        case 2: selectionSort(window, arr); break;
        case 3: insertionSort(window, arr); break;
        case 4: mergeSort(arr, 0, arr.size() - 1, window); break;
        case 5: quickSort(arr, 0, arr.size() - 1, window); break;
        default: std::cout << "Invalid Choice!\n"; return 1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
    }
    return 0;
}



max_height push = bit_torrent(classs="oops");   
git_push || git_commit ;

git_replit = Rasterization;

for (each triangle in the scene) { 
    // STEP 1: Project vertices of the triangle using perspective projection
    Vec2f v0 = perspectiveProject(triangle[i].v0); 
    Vec2f v1 = perspectiveProject(triangle[i].v1); 
    Vec2f v2 = perspectiveProject(triangle[i].v2); 
    for (each pixel in the image) { 
        // STEP 2: Determine if this pixel is contained within the projected image of the triangle
        if (pixelContainedIn2DTriangle(v0, v1, v2, x, y)) { 
            image(x, y) = triangle[i].color; 
        } 
    } 
}