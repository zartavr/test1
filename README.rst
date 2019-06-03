===============
Проект «Шаблон»
===============

----------------------------------------
Шаблон для упрощённого создания проектов
----------------------------------------


1 Структура проекта
===================

1.1 Корневая директория
-----------------------

Структура папок корневой директории описана в Redmine:
`Создание и работа над проектом
<http://redmine.pin/easy_knowledge_stories/80>`_.


1.2 Папка emb
-------------

В папке **emb** располагается исходный код ВПО (встраиваемого
программного обеспечения). Структура папки **emb** частично
продиктована CMake-ом, который используется для сборки проекта.

Основные файлы и папки **emb**:

- **.gitignore** - основной список файлов для игнорирования
  git-ом;

- **CMakeLists.txt** — корневой CMakeLists.txt;

- **.clang-format** — файл настроек для ClangFormat

- **lib** — содержит скомпилированные библиотеки, а так
  же их *Config.cmake* файлы в поддериктории **cmake**.
  Все файлы и директории должны быть добавлены в игнорлист,
  кроме самой папки **cmake**;

- **include** — содержит заголовочные файлы скомпилированных
  и установленных библиотек; Все файлы этой директории должны
  быть добавлены в игнорлист;

- **bin** — содержит бинарные файлы (elf, bin) которые были
  сгенерированы в процессе компиляции. Файлы попадают в эту
  директорию после запуска ``make install`` для проекта при
  указании этой директории в качестве ``CMAKE_INSTALL_PREFIX``;

- **cmake** — содержит *.cmake*-файлы для упрощённого менеджмента
  CMake структуры проекта. Данная папка должна подключаться как
  git `submodule` репозитория `CMake files <https://gitlab.pin
  /thirdpin_team/cmake-files>`_;

- **patches** - содержит git-патчи для 3th party библиотек,
  которые компилируются в процессе компиляции проекта
  (например для `libopencm3 <https://github.com/libopencm3/
  libopencm3>`_);

- **util** — содержит доп. утилиты для работы с проектом, а так
  же *launch*-файлы для работы с отладчиком в Eclipse/TrueStudio;

- **.vscode** [опционально] — может хранить в себе файлы для
  конфигурации `VS Code <https://code.visualstudio.com/>`_  и
  его расширений. Может включать такие файлы как:

  - **c_cpp_properties.json** —
    настройка `C/C++ расширения
    <https://github.com/microsoft/vscode-cpptools/
    blob/master/Documentation/Getting%20started%20with
    %20IntelliSense%20configuration.md>`_
  - **cmake-kits.json** — настройка toolchain для
    `расширения CMake <https://vector-of-bool.github.io/
    docs/vscode-cmake-tools/kits.html>`_
  - **launch.json** — настройка `отладки <https://code.
    visualstudio.com/docs/editor/debugging>`_ приложения
    для `расширения Cortex Debug <https://marketplace.
    visualstudio.com/items?itemName=marus25.cortex-debug>`_
  - **.gitignore** — игнорируемые Git-ом файлы, должны быть
    включены все файлы, кроме перечисленных выше;

- **.cproject**, **.project** [опционально] — файлы проекта
  Eclipce/TrueStudio, появляются только после импорта
  папки с проектом в IDE, инструкция тут: `Настройка и
  использование CMake <http://redmine.pin/easy_knowledge_stories
  /116>`_;

- **STM32Fxxx.svd** [опционально] — `файл описывающий регистры
  <https://www.keil.com/pack/doc/CMSIS/SVD/html/svd_Format_pg.html>`_
  периферии МК от STM32. Скачать можно здесь: `posborne/cmsis-svd
  <https://github.com/posborne/cmsis-svd/tree/master/data/STMicro>`_;
  данный файл используется расширением Cortex Debug для VS Code;

- **cmake-variants.yaml** [опционально] — файл, описывающий
  возможные конфигурации сборки CMake и соответствующие им
  ``-D`` флаги;

- **test** [зарезервировано] - данная папка зарезервирована для
  будущего использования.


2. How to use
=============

1. Клонировать шаблон в папку с названием будущего проекта:

   .. code-block:: bash

        git clone git@gitlab.pin:thirdpin_team/project-template.git myproject

   где вместо ``myproject`` название вашего проекта.

2. Проект по-умолчанию включает в себя в качестве submodules
   следующие репозитории:

   - **libopencm3** (/emb/src/libopencm3) — опциональная
     библиотека `OpenCM3 <https://libopencm3.org/>`_ для
     работы с периферией контроллеров;

   - **etl** (/emb/src/etl) — опциональная библиотека
     `Embedded Template Library <https://www.etlcpp.com/>`_
     с множеством полезных классов заменяющих и
     дополняющих std;

   - **cmake** (/cmake) — **обязательный** submodule с
     CMake-файлами необходимыми для сборки проекта и
     библиотек.

   **ВАЖНО**: если вы хотите убрать из сборки одну из
   представленных выше опциональных бибилотек необходимо
   сделать следующее (на примере etl):

   1) деинициализировать submodule:

      .. code-block:: bash

        git submodule deinit /emb/src/etl

   2) удалить папку с submodule;

      .. code-block:: bash

        git rm /emb/src/etl

   3) сделать коммит с удалённым модулем;
   4) удалить папку ``/.git/modules/emb/src/etl``.

3. Изменить ``remote`` локального репозитория на новый
   заранее созданный удалённый пустой репозиторий:

   .. code-block:: bash

       git remote set-url origin git@gitlab.pin:thirdpin_team/myproject.git

   где вместо ``myproject.git`` ваш репозиторий.

4. Поменять имя проекта в файле ``/emb/CMakeLists.txt``.

5. Папку ``/emb/src/template`` переименовать в папку с именем
   вашего проекта; добавить новую папку в
   ``/emb/src/CMakeLists.txt``.

6. Если в проекте несколько подпроектов, то в файле
   ``/emb/src/myproject/CMakeLists.txt`` необходимо изменить
   ``project(...)`` на имя вашего подпроекта.

7. Собрать.

8. Сделать push.
