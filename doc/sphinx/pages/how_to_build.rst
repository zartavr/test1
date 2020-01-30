.. _how_to_build:

How to build
============

Необходимые зависимости
-----------------------

Основные зависимости для сборки любого проекта это:

- `CMake <https://cmake.org/>`__ [in PATH] — основной
  инструмент для организации и сборки проекта;

- `Ninja <https://ninja-build.org/>`__ [in PATH] — более
  легковесная, быстрая и портативная альтернатива `make
  <https://ru.wikipedia.org/wiki/Make>`__;

- компилятор (любой из) [in PATH]:

  - `GNU ARG GCC <https://developer.arm.com/
    tools-and-software/open-source-software/developer-tools
    /gnu-toolchain/gnu-rm>`__ — форк ``gcc``, поставляемый
    компанией ARM;

  - `Clang <http://releases.llvm.org/download.html#8.0.0>`__ —
    современный компилятор, пришедший на замену ``gcc``,
    поддерживает компиляцию под ARM;

- `Windows Subsystem for Linux (WSL) <https://docs.microsoft.
  com/ru-ru/windows/wsl/install-win10>`__ [только для Windows] —
  слой совместимости для запуска Linux-приложений, необходим
  для сборки библиотеки OpenCM3. Так же требуется установить
  следующие пакеты в WSL:

  - make
  - python
  - `gcc-arm-embedded <https://launchpad.net/
    ~team-gcc-arm-embedded/+archive/ubuntu/ppa>`__
  - git


Порядок сборки
--------------

    Далее будет описана сборка исключительно с использованием консоли.
    Описание настройки сборки из-под IDE ищите в Redmine.

Перед началом сборки необходимо создать папку **/emb/build** и перейти
в неё.


Конфигурация
++++++++++++

Для запуска конфигурации необходимо указать флаги:

- `\-DCMAKE_TOOLCHAIN_FILE` — пусть до toolchain-файла, выбирается
  в зависимости от компилятора. Для Clang это
  "cmake/toolchains/toolchain-clang.cmake";

- `\-DCMAKE_BUILD_TYPE` — тип сборки два основных это *Debug* и
  *Release*. В последнем во время компиляции добавляются флаги
  оптимизации (обычно O3), убираются символы отладки из бинарика
  и добавляется дефайн :cpp:`NDEBUG`. Другие типы сборки можно
  посмотреть в `документации CMake <https://cmake.org/cmake/help
  /git-stage/variable/CMAKE_BUILD_TYPE.html>`__.

- `\-DTOOLCHAIN_CORTEX_CONFIG` — выбор ядра, для которого
  осуществляется компиляция. По-умолчанию, это *cortex-m3*,
  но возможны варианты *cortex-m0*, *cortex-m4* и *cortex-a9*.

- `\-GNinja` — выбор генератора, т.е. по сути это выбор формата
  генерируемых Makefile-ов. Так как мы используем Ninja, то флаг
  соответствующий;

- `\-DCMAKE_INSTALL_PREFIX` [опционально] — место установки
  бинарников и сопровождающих файлов. Может быть использовано
  при создании релизов, но для сборки не обязательно.

Итого получаем:

.. code-block:: bash

    mrdir build
    cd build
    cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/toolchain-clang.cmake -DTOOLCHAIN_CORTEX_CONFIG=cortex-m4 -DCMAKE_BUILD_TYPE=Release -GNinja ..

Если для запуска используется **PowerShell** необходимо указывать
абсолютный путь до toolchain-файла. Последние две точки в команде
указывают на расположение корневого `CMakeLists.txt` файла.


Сборка
++++++

Для сборки необходимо запустить следующую команду, находясь
в папке **emb/src/build**:

.. code-block:: bash

    cmake --build . --target all

Для сборки конкретной целим можно вместо ``all`` указать
имя цели, например

.. code-block:: bash

    cmake --build . --target my_subproject

Для сборки и установки используется команда

.. code-block:: bash

    cmake --build . --target install

Gitlab CI
---------

Для описания порядка работы с артефактами используется файл
**.gitlab-ci.yml**. В данном шаблоне представлена простейшая
его реализация, которая позволяет собрать проект на сервере
Gitlab и скопировать полученные артефакты. В файле необходимо
исправить все пути до артефактов на актуальные и добавить
необходимые, если подпроектов больше, чем один.

В дальнейшем данный раздел будет описан подробнее, а шаблонный
**.gitlab-ci.yml** будет доработан.
