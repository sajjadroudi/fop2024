#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_LENGTH 100
#define MAX_ALBUM_COUNT 20

#define USER_AND_SINGER_REQUEST 1
#define USER_AND_GENRE_REQUEST 2
#define AGE_AND_SINGER_REQUEST 3
#define AGE_AND_GENRE_REQUEST 4
#define CITY_AND_SINGER_REQUEST 5
#define CITY_AND_GENRE_REQUEST 6

struct User {
    char name[20];
    int age;
    char city[20];
    int albumCount;
    char albumNames[MAX_ALBUM_COUNT][20];
};

struct Album {
    char name[20];
    char singer[20];
    char genre[20];
    int trackCount;
};

int userCount, albumCount, queryCount;
struct User users[MAX_ARRAY_LENGTH];
struct Album albums[MAX_ARRAY_LENGTH];

int findUserIndex(char userName[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, userName) == 0) {
            return i;
        }
    }
    return -1;
}

int findAlbumIndex(char albumName[]) {
    for (int i = 0; i < albumCount; i++) {
        if (strcmp(albums[i].name, albumName) == 0) {
            return i;
        }
    }
    return -1;
}

int getCountOfSingerSongsBoughtByUser(char userName[], char singer[]) {
    int userIndex = findUserIndex(userName);
    if (userIndex < 0)
        return 0;

    struct User user = users[userIndex];

    int count = 0;
    for (int i = 0; i < user.albumCount; i++) {
        int albumIndex = findAlbumIndex(user.albumNames[i]);

        struct Album album = albums[albumIndex];

        if (strcmp(album.singer, singer) == 0)
            count += album.trackCount;
    }

    return count;
}

int getCountOfGenreSongsBoughtByUser(char userName[], char genre[]) {
    int userIndex = findUserIndex(userName);

    if (userIndex < 0)
        return 0;

    struct User user = users[userIndex];

    int count = 0;

    for (int i = 0; i < user.albumCount; i++) {
        int albumIndex = findAlbumIndex(user.albumNames[i]);

        struct Album album = albums[albumIndex];

        if (strcmp(album.genre, genre) == 0)
            count += album.trackCount;
    }

    return count;
}

int getCountOfSingerSongsBoughtByUserInSpecificAge(int age, char singer[]) {
    int count = 0;
    for (int i = 0; i < userCount; i++) {
        if (users[i].age != age)
            continue;

        struct User user = users[i];

        for (int j = 0; j < user.albumCount; j++) {
            int albumIndex = findAlbumIndex(user.albumNames[j]);
            struct Album album = albums[albumIndex];
            if (strcmp(album.singer, singer) == 0)
                count += album.trackCount;
        }
    }
    return count;
}

int getCountOfGenreSongsBoughtByUserInSpecificAge(int age, char genre[]) {
    int count = 0;

    for (int i = 0; i < userCount; i++) {
        if (users[i].age != age)
            continue;

        struct User user = users[i];

        for (int j = 0; j < user.albumCount; j++) {
            int albumIndex = findAlbumIndex(user.albumNames[j]);
            struct Album album = albums[albumIndex];
            if (strcmp(album.genre, genre) == 0)
                count += album.trackCount;
        }
    }

    return count;
}

int getCountOfSingerSongsBoughtByUserInSpecificCity(char city[], char singer[]) {
    int count = 0;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].city, city) != 0)
            continue;

        struct User user = users[i];

        for (int j = 0; j < user.albumCount; j++) {
            int albumIndex = findAlbumIndex(user.albumNames[j]);

            struct Album album = albums[albumIndex];

            if (strcmp(album.singer, singer) == 0)
                count += album.trackCount;
        }
    }

    return count;
}

int getCountOfGenreSongsBoughtByUserInSpecificCity(char city[], char genre[]) {
    int count = 0;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].city, city) != 0)
            continue;

        struct User user = users[i];

        for (int j = 0; j < user.albumCount; j++) {
            int albumIndex = findAlbumIndex(user.albumNames[j]);
            struct Album album = albums[albumIndex];
            if (strcmp(album.genre, genre) == 0)
                count += album.trackCount;
        }
    }

    return count;
}

int processRequest(int type, char in1[], char in2[]) {
    switch (type) {
        case USER_AND_SINGER_REQUEST:
            return getCountOfSingerSongsBoughtByUser(in1, in2);
        case USER_AND_GENRE_REQUEST:
            return getCountOfGenreSongsBoughtByUser(in1, in2);
        case AGE_AND_SINGER_REQUEST:
            return getCountOfSingerSongsBoughtByUserInSpecificAge(atoi(in1), in2);
        case AGE_AND_GENRE_REQUEST:
            return getCountOfGenreSongsBoughtByUserInSpecificAge(atoi(in1), in2);
        case CITY_AND_SINGER_REQUEST:
            return getCountOfSingerSongsBoughtByUserInSpecificCity(in1, in2);
        case CITY_AND_GENRE_REQUEST:
            return getCountOfGenreSongsBoughtByUserInSpecificCity(in1, in2);
    }
    return 0;
}

void readUsersInformation() {
    char dummyInput[20];

    scanf("%d", &userCount);
    for (int i = 0; i < userCount; i++) {
        scanf("%s", dummyInput);
        scanf("%s", users[i].name);

        scanf("%s", dummyInput);
        scanf("%d", &users[i].age);

        scanf("%s", dummyInput);
        scanf("%s", users[i].city);

        scanf("%s", dummyInput);
        scanf("%d", &users[i].albumCount);

        for (int j = 0; j < users[i].albumCount; j++) {
            scanf("%s", users[i].albumNames[j]);
        }
    }
}

void readAlbumsInformation() {
    char dummyInput[20];

    scanf("%d", &albumCount);
    for (int i = 0; i < albumCount; i++) {
        scanf("%s", dummyInput);
        scanf("%s", albums[i].name);

        scanf("%s", dummyInput);
        scanf("%s", albums[i].singer);

        scanf("%s", dummyInput);
        scanf("%s", albums[i].genre);

        scanf("%s", dummyInput);
        scanf("%d", &albums[i].trackCount);
    }
}

void readAndProcessRequests() {
    scanf("%d", &queryCount);
    int type;
    char input1[20], input2[20];
    for (int i = 0; i < queryCount; i++) {
        scanf("%d", &type);
        scanf("%s", input1);
        scanf("%s", input2);

        int answer = processRequest(type, input1, input2);

        printf("%d\n", answer);
    }
}

int main() {
    readUsersInformation();
    readAlbumsInformation();
    readAndProcessRequests();
    return 0;
}