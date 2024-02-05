#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Location;

typedef struct {
    char name[16];
    int numLocations;
    Location *locations;
} City;

typedef struct {
    int city1, city2;
} FiberLink;

double calculateDistance(Location loc1, Location loc2) {
    return sqrt(pow(loc2.x - loc1.x, 2) + pow(loc2.y - loc1.y, 2));
}

double calculateTotalFiberLength(City *cities, FiberLink *links, int numCities) {
    double **dp = (double **)malloc(numCities * sizeof(double *));
    for (int i = 0; i < numCities; i++) {
        dp[i] = (double *)malloc(numCities * sizeof(double));
        for (int j = 0; j < numCities; j++) {
            dp[i][j] = INFINITY;
        }
    }

    for (int i = 0; i < numCities; i++) {
        City city = cities[i];
        for (int j = 0; j < city.numLocations; j++) {
            Location loc1 = city.locations[j];
            dp[i][i] = 0.0;
            for (int k = i + 1; k < numCities; k++) {
                City otherCity = cities[k];
                for (int l = 0; l < otherCity.numLocations; l++) {
                    Location loc2 = otherCity.locations[l];
                    double distance = calculateDistance(loc1, loc2);
                    if (distance < dp[i][k]) {
                        dp[i][k] = distance;
                        dp[k][i] = dp[i][k];
                    }
                }
            }
        }
    }

    for (int i = 0; i < numCities - 1; i++) {
        FiberLink link = links[i];
        dp[link.city1][link.city2] = 0.0;
        dp[link.city2][link.city1] = 0.0;
    }

    for (int k = 0; k < numCities; k++) {
        for (int i = 0; i < numCities; i++) {
            if (i == k) continue;
            for (int j = 0; j < numCities; j++) {
                if (j == i || j == k) continue;
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    double totalLength = 0.0;
    for (int i = 0; i < numCities; i++) {
        for (int j = i + 1; j < numCities; j++) {
            totalLength += dp[i][j];
        }
    }

    for (int i = 0; i < numCities; i++) {
        free(dp[i]);
    }
    free(dp);

    return totalLength;
}

int main() {
    int numCities;

    while (1) {
        scanf("%d", &numCities);
        if (numCities == 0) {
            break;
        }

        City *cities = (City *)malloc(numCities * sizeof(City));
        FiberLink *links = (FiberLink *)malloc((numCities - 1) * sizeof(FiberLink));

        for (int i = 0; i < numCities; i++) {
            scanf("%s %d", cities[i].name, &cities[i].numLocations);
            cities[i].locations = (Location *)malloc(cities[i].numLocations * sizeof(Location));
            for (int j = 0; j < cities[i].numLocations; j++) {
                scanf("%d %d", &cities[i].locations[j].x, &cities[i].locations[j].y);
            }
        }

        for (int i = 0; i < numCities - 1; i++) {
            scanf("%s %s", cities[links[i].city1].name, cities[links[i].city2].name);
        }

        double totalLength = calculateTotalFiberLength(cities, links, numCities);
        printf("%.1lf\n", totalLength);

        for (int i = 0; i < numCities; i++) {
            free(cities[i].locations);
        }
        free(cities);
        free(links);
    }

    return 0;
}
