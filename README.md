# Сборка Проекта

Для сборки можно использовать либо `gradlew.bat` либо `gradle` из переменных окржения.  
Пример сборки через gradle:

```
gradle clean build
```

Пример сборки через gradlew.bat:

```
./gradlew clean build
```

# Запуск Проекта

Запуск осуществляется из директории `build`.  
Пример запуска программы:

```
./app/build/exe/main/debug/app
```

Или можно воспользоваться задачей `start`.

```
gradle start
```
