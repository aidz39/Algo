#include <stdio.h>
#include <stdlib.h>

// دالة تقوم بإنشاء سلسلة من الأحرف بحجم معين
char *ChargerChaine(int N) {
    char *chaine = (char*)malloc((N+1) * sizeof(char)); // تخصيص مساحة في الذاكرة تكفي لحفظ N حرفاً بالإضافة إلى '\0' (نهاية السلسلة)
    if (chaine == NULL) { // التحقق من نجاح تخصيص الذاكرة
        printf("Erreur d'allocation mémoire.\n"); // طباعة رسالة خطأ في حالة فشل التخصيص
        exit(1); // إنهاء البرنامج
    }
    printf("Entrez une chaîne de %d caractères : ", N); // طلب إدخال سلسلة نصية من المستخدم
    fgets(chaine, N+1, stdin); // قراءة السلسلة النصية المدخلة (بحد أقصى N حرفاً)
    chaine[strcspn(chaine, "\n")] = '\0'; // إزالة حرف السطر الجديد '\n' إذا تم إدخاله
    return chaine; // إعادة السلسلة النصية
}

// دالة لحساب طول السلسلة النصية
int Longueur(char *ch) {
    int i = 0;
    while (ch[i] != '\0') { // تكرار حتى الوصول إلى نهاية السلسلة
        i++;
    }
    return i; // إرجاع طول السلسلة
}

// دالة لنسخ محتويات السلسلة النصية إلى مصفوفة
void ChargerTab(char *p, char Tab[]) {
    int i = 0;
    while (*p != '\0') { // التكرار حتى نهاية السلسلة النصية
        Tab[i] = *p; // نسخ الحرف الحالي إلى المصفوفة
        i++;
        p++; // الانتقال إلى الحرف التالي
    }
    Tab[i] = '\0'; // إضافة علامة نهاية السلسلة
}

// دالة لعكس محتويات مصفوفة الأحرف
void InverserTab(char Tab[], char T[], int m) {
    int i = 0, j = m - 1; // تحديد المؤشر الأول (i) والأخير (j) في المصفوفة
    while (i < j) { // التكرار حتى تتقاطع المؤشرات
        char temp = Tab[i]; // تبديل الحروف بين المواضع الأولى والأخيرة
        Tab[i] = Tab[j];
        Tab[j] = temp;
        i++;
        j--;
    }
}

// دالة لطباعة محتويات مصفوفة الأحرف
void AfficherTab(char Tab[], int m) {
    for (int i = 0; i < m; i++) { // التكرار على عناصر المصفوفة
        printf("%c", Tab[i]); // طباعة كل حرف
    }
    printf("\n"); // الانتقال إلى سطر جديد
}

int main() {
    int n; // متغير لحفظ حجم السلسلة النصية
    printf("Veuillez saisir la taille maximale de la chaîne : "); // طلب الحجم الأقصى للسلسلة من المستخدم
    scanf("%d", &n); // قراءة الحجم المدخل
    getchar(); // للتخلص من أي أحرف متبقية في المخزن المؤقت (مثل '\n')

    char *ch = ChargerChaine(n); // استدعاء دالة إنشاء السلسلة النصية
    int m = Longueur(ch); // حساب طول السلسلة النصية

    char Tab[m], T[m]; // إنشاء مصفوفتين بنفس طول السلسلة النصية
    ChargerTab(ch, Tab); // نسخ محتويات السلسلة النصية إلى المصفوفة

    printf("Chaîne initiale : "); // طباعة النص الأصلي
    AfficherTab(Tab, m);

    InverserTab(Tab, T, m); // عكس محتويات المصفوفة
    printf("Chaîne inversée : "); // طباعة النص بعد عكسه
    AfficherTab(T, m);

    free(ch); // تحرير الذاكرة المحجوزة
    return 0; // إنهاء البرنامج
}

شرح الوظائف:

ChargerChaine: تقوم بحجز مساحة في الذاكرة، ثم تطلب من المستخدم إدخال سلسلة نصية وتُعيد هذه السلسلة.

Longueur: تحسب طول السلسلة النصية عن طريق المرور على كل حرف حتى الوصول لنهايتها.

ChargerTab: تقوم بنسخ محتويات السلسلة النصية إلى مصفوفة.

InverserTab: تعكس ترتيب الأحرف في مصفوفة الأحرف.

AfficherTab: تقوم بعرض محتويات مصفوفة الأحرف على الشاشة.

main: يدير البرنامج عن طريق استدعاء الدوال بالترتيب المناسب، ويقوم بإدارة الإدخال والإخراج.


#include <stdio.h>
#include <stdlib.h>

// دالة تقوم بإنشاء سلسلة من الأحرف بحجم معين
char *ChargerChaine(int N) {
    char *chaine = (char*)malloc((N+1) * sizeof(char)); // تخصيص مساحة في الذاكرة تكفي لحفظ N حرفاً بالإضافة إلى '\0' (نهاية السلسلة)
    if (chaine == NULL) { // التحقق من نجاح تخصيص الذاكرة
        printf("Erreur d'allocation mémoire.\n"); // طباعة رسالة خطأ في حالة فشل التخصيص
        exit(1); // إنهاء البرنامج
    }
    printf("Entrez une chaîne de %d caractères : ", N); // طلب إدخال سلسلة نصية من المستخدم
    fgets(chaine, N+1, stdin); // قراءة السلسلة النصية المدخلة (بحد أقصى N حرفاً)
    chaine[strcspn(chaine, "\n")] = '\0'; // إزالة حرف السطر الجديد '\n' إذا تم إدخاله
    return chaine; // إعادة السلسلة النصية
}

// دالة لحساب طول السلسلة النصية
int Longueur(char *ch) {
    int i = 0;
    while (ch[i] != '\0') { // تكرار حتى الوصول إلى نهاية السلسلة
        i++;
    }
    return i; // إرجاع طول السلسلة
}

// دالة لنسخ محتويات السلسلة النصية إلى مصفوفة
void ChargerTab(char *p, char Tab[]) {
    int i = 0;
    while (*p != '\0') { // التكرار حتى نهاية السلسلة النصية
        Tab[i] = *p; // نسخ الحرف الحالي إلى المصفوفة
        i++;
        p++; // الانتقال إلى الحرف التالي
    }
    Tab[i] = '\0'; // إضافة علامة نهاية السلسلة
}

// دالة لعكس محتويات مصفوفة الأحرف
void InverserTab(char Tab[], char T[], int m) {
    int i = 0, j = m - 1; // تحديد المؤشر الأول (i) والأخير (j) في المصفوفة
    while (i < j) { // التكرار حتى تتقاطع المؤشرات
        char temp = Tab[i]; // تبديل الحروف بين المواضع الأولى والأخيرة
        Tab[i] = Tab[j];
        Tab[j] = temp;
        i++;
        j--;
    }
}

// دالة لطباعة محتويات مصفوفة الأحرف
void AfficherTab(char Tab[], int m) {
    for (int i = 0; i < m; i++) { // التكرار على عناصر المصفوفة
        printf("%c", Tab[i]); // طباعة كل حرف
    }
    printf("\n"); // الانتقال إلى سطر جديد
}

int main() {
    int n; // متغير لحفظ حجم السلسلة النصية
    printf("Veuillez saisir la taille maximale de la chaîne : "); // طلب الحجم الأقصى للسلسلة من المستخدم
    scanf("%d", &n); // قراءة الحجم المدخل
    getchar(); // للتخلص من أي أحرف متبقية في المخزن المؤقت (مثل '\n')

    char *ch = ChargerChaine(n); // استدعاء دالة إنشاء السلسلة النصية
    int m = Longueur(ch); // حساب طول السلسلة النصية

    char Tab[m], T[m]; // إنشاء مصفوفتين بنفس طول السلسلة النصية
    ChargerTab(ch, Tab); // نسخ محتويات السلسلة النصية إلى المصفوفة

    printf("Chaîne initiale : "); // طباعة النص الأصلي
    AfficherTab(Tab, m);

    InverserTab(Tab, T, m); // عكس محتويات المصفوفة
    printf("Chaîne inversée : "); // طباعة النص بعد عكسه
    AfficherTab(T, m);

    free(ch); // تحرير الذاكرة المحجوزة
    return 0; // إنهاء البرنامج
}

