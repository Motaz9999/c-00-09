#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

void printHeader(const std::string& title)
{
    std::cout << "\n======================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "======================================" << std::endl;
}

int main()
{
    // ---------------------------------------------------------
    // 1. الاختبار الأساسي المطلوب في الـ Subject بالحرف
    // ---------------------------------------------------------
    printHeader("1. SUBJECT MANDATORY TEST");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria* tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    // ---------------------------------------------------------
    // 2. اختبار سعة MateriaSource (التعلم والبحث عن أنواع غير موجودة)
    // ---------------------------------------------------------
    printHeader("2. MATERIASOURCE CAPACITY & UNKNOWN TYPES");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        // محاولة تعلم عنصر خامس (المصدر ممتلئ - 4 قوالب كحد أقصى)
        AMateria* extra = new Ice();
        src->learnMateria(extra); // يجب ألا ينهار ويحرر الذاكرة بأمان

        // محاولة توليد نوع غير معروف
        AMateria* unknown = src->createMateria("fire");
        if (unknown == NULL)
            std::cout << "[SUCCESS] Correctly returned NULL for unknown Materia 'fire'." << std::endl;

        delete src;
    }

    // ---------------------------------------------------------
    // 3. اختبار امتلاء الحقيبة (Inventory Full) وتمرير مؤشر NULL
    // ---------------------------------------------------------
    printHeader("3. INVENTORY LIMITS & NULL EQUIP");
    {
        ICharacter* cloud = new Character("Cloud");
        ICharacter* enemy = new Character("Sephiroth");

        cloud->equip(NULL); // تمرير NULL - يجب ألا ينهار البرنامج

        AMateria* m0 = new Ice();
        AMateria* m1 = new Cure();
        AMateria* m2 = new Ice();
        AMateria* m3 = new Cure();
        AMateria* m4 = new Ice(); // عنصر زائد

        cloud->equip(m0);
        cloud->equip(m1);
        cloud->equip(m2);
        cloud->equip(m3);
        cloud->equip(m4); // الحقيبة ممتلئة (4 خانات) - يجب عدم تجهيزه

        // بما أن m4 لم يُجهز داخل الحقيبة، يجب حذفه يدوياً لتفادي الـ Leaks
        delete m4;

        cloud->use(0, *enemy);
        cloud->use(1, *enemy);
        cloud->use(2, *enemy);
        cloud->use(3, *enemy);

        // محاولة استخدام خانات غير موجودة أو خارج النطاق (Out of bounds)
        cloud->use(-1, *enemy);
        cloud->use(4, *enemy);
        cloud->use(10, *enemy);

        delete enemy;
        delete cloud;
    }

    // ---------------------------------------------------------
    // 4. اختبار unequip وترك المواد دون تدميرها (Floor Handling)
    // ---------------------------------------------------------
    printHeader("4. UNEQUIP & FLOOR HANDLING");
    {
        ICharacter* tifa = new Character("Tifa");
        ICharacter* target = new Character("Target");

        AMateria* mat = new Ice();
        tifa->equip(mat);
        tifa->use(0, *target);

        // unequip للخانة 0 (إذا طبقت نظام الـ Floor Linked List داخلياً فلن تحتاج لحذفه يدوياً)
        // إذا كنت تدير العناوين في الـ main: احتفظ بالعنوان قبل الـ unequip
        tifa->unequip(0);

        // محاولة استخدام الخانة بعد الـ unequip (أصبحت فارغة، يجب ألا تطبع شيئاً وألا تنهار)
        tifa->use(0, *target);

        // محاولة عمل unequip لخانات فارغة أو خارج النطاق
        tifa->unequip(0);
        tifa->unequip(-5);
        tifa->unequip(42);

        delete target;
        delete tifa;
        
        // إذا لم تكن تستخدم نظام الـ Floor Linked List داخل كلاس Character:
        // delete mat;
    }

    // ---------------------------------------------------------
    // 5. اختبار الـ Deep Copy (Copy Constructor & Assignment Operator)
    // ---------------------------------------------------------
    printHeader("5. DEEP COPY VERIFICATION (NO SHALLOW COPY)");
    {
        Character* original = new Character("Original");
        original->equip(new Ice());
        original->equip(new Cure());

        // اختبار Copy Constructor
        Character* copyConstructed = new Character(*original);

        // اختبار Copy Assignment Operator
        Character assigned("Assigned");
        assigned.equip(new Ice()); // نضع فيها عنصراً قديماً لنتأكد أنه سيُحذف قبل النسخ
        assigned = *original;

        // حذف الكائن الأصلي للتأكد من أن النسخ تمتلك نسخاً مستقلة تماماً (Deep Copy)
        delete original;

        ICharacter* dummy = new Character("Dummy");
        std::cout << "-- Testing Copy Constructed Character after original deletion --" << std::endl;
        copyConstructed->use(0, *dummy);
        copyConstructed->use(1, *dummy);

        std::cout << "-- Testing Assigned Character after original deletion --" << std::endl;
        assigned.use(0, *dummy);
        assigned.use(1, *dummy);

        delete dummy;
        delete copyConstructed;
    }

    printHeader("ALL TESTS COMPLETED SUCCESSFULLY");
    return 0;
}