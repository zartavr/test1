Как использовать
================

Предположим, ваш проект верхнего уровня называется ``my_project`` и имеет под
проект ``my_subproject``. Ниже представлены шаги, которые необходимо проделать,
чтобы создать требуемый проект из шаблона.

1. Клонировать шаблон в папку с названием будущего проекта:

   .. code-block:: bash

        $ git clone --recurse-submodules git@gitlab.pin:thirdpin_team/project-template.git myproject

2. Проект по-умолчанию включает в себя в качестве submodules
   следующие репозитории:

   - **cmake** (/external/cmake) — **обязательный** submodule с
     CMake-файлами необходимыми для сборки проекта и библиотек.

   - **libopencm3** (/external/libopencm3) — *рекомендуемая*
     библиотека `OpenCM3 <https://libopencm3.org/>`__ для
     работы с периферией контроллеров;

   - **cm3cpp** (/external/cm3cpp) — *рекомендуемая* библиотека
     `cm3cpp <https://github.com/thirdpin/libopencm3_cpp_extensions>`__.
     Плюсовая обётка над libopencm3;

   - **tplib** (/external/tplib) — *рекомендуемая* библиотека
     `ThirdPin snippets library <https://gitlab.thirdpin.io/thirdpin_team/tplib>`__
     Набор полезных классов и функций. Требует наличия **cm3cpp**;

   - **etl** (/external/etl) — *рекомендуемая* библиотека
     `Embedded Template Library <https://www.etlcpp.com/>`__
     с множеством полезных классов заменяющих и
     дополняющих std;

   - **named_type** (/external/named_type) — *рекомендуемая* библиотека
     `Named type <https://github.com/joboccara/NamedType>`__
     для создания "строгих" обёрток над типами. Подробнее
     можно почитать в этой серии статей: `Strong types for strong interfaces
     <https://www.fluentcpp.com/2016/12/08/strong-types-for-strong-interfaces/>`__;

   - **expected** (//external/expected) — *рекомендуемая* библиотека
     `expected <https://github.com/TartanLlama/expected>`__
     являющаяся одной из возможных реализаций ``std::expected``.
     Документация: `tl libraries <https://tl.tartanllama.xyz>`__;

   - **magic_enum** (/external/magic_enum) — *рекомендуемая* библиотека
     `magic_enum <https://github.com/thirdpin/magic_enum>`__
     добавляющая возможности для рефлексии enum-ов (вычисление размера
     enum, каст значений enum к строке, итерация по значениям enum).
     Документация: `magic_enum Reference <https://github.com/thirdpin/magic_enum/
     blob/master/doc/reference.md>`__;

   - **yxml** (/external/yxml) — опциональная библиотека
     `yxml <https://code.blicky.net/yorhel/yxml>`__ для парсинга xml. В проекте
     использована только как пример интеграции non-cmake зависимостей;

.. Important::

   Если вы хотите убрать из сборки одну из
   представленных выше опциональных библиотек необходимо
   сделать следующее (на примере **yxml**):

   1) деинициализировать submodule:

      .. code-block:: bash

        $ git submodule deinit external/yxml/yxml

   2) удалить папку с submodule;

      .. code-block:: bash

        $ git rm -r external/yxml

   3) удалить строчку ``add_subdirectory(yxml)``
      в файле **/external/CMakeLists.txt**;
   4) сделать коммит с удалённым модулем;
   5) удалить папку ``/.git/modules/external/yxml/yxml``.

3. Изменить ``remote`` локального репозитория на новый
   заранее созданный удалённый пустой репозиторий:

   .. code-block:: bash

       $ git remote set-url origin <your-git-repo-url>

4. Поменять имя проекта верхнего уровня в файле ``/CMakeLists.txt``.

.. Note::
   Для для именования проектов и подпроектов лучше использовать латинские буквы
   при необходимости разделённые символом подчёркивания "\_". Символ дефиса "-"
   для разделения слов лучше не использовать.

   Имя основной цели проекта и имя проекта должны совпадать.

5. В файле ``/src/CMakeLists.txt`` необходимо изменить ``project(...)`` на имя
   вашего проекта.

6. Удалить из ``target_link_libraries`` у подпроекта лишние библиотеки.

7. Удалить из **main.cpp** лишний код.

8. Добавить файл линкера **myproject.ld** в папку
    **/src/ldscripts/**.

9. Собрать (см. :ref:`how_to_build`).

10. Исправить файл **/.gitlab-ci.yml**: исправить пути до
    компилируемых бинарников.

11. Настроить пути до бинарников и параметры отладочной платы в
    **.vscode/launch.json**.

11. Сделать commit, push.
