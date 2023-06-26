//                      بســـــــــــم الله الرحــــــــمن الرحـــــــــيم
#include <bits/stdc++.h>
using namespace std;
#define loopi(n) for(int i= 0 ; i<n; i++)
#define loopI(n) for(int i = 1; i<=n; i++)

void Bug_Busters()
{
  cin.tie(0);
  cin.sync_with_stdio(0); 
}

void test()
{
    cout << "Here everything is OK!" << endl;
}


bool estability, campaign, meeting , tasks, training, good_leader, good_member, event_work, active;
string choice = "اختر رقماً واحداً من هؤلاء يعبر عن السبب، إذا أردت اختيار سبب آخر اختر هذا أولاً وأعد الاختيار.";
string choose_again = "إذا كنت تريد الاختيار مجدداً من فضلك اختر رقم المقترح، وإن لم تكن تريد الإضافة فاختر أي رقم سالب";
string stable = "بسبب ";
string be_clear = "وضح من فضلك.";

bool good_audience = false, done_taskts = false, good_training = false;



vector <string> Estability =
 {
    "الالتزام بالتاسكات وتسليمها في موعدها",
    "الالتزام بسياسة الاعتذار",
    " آخر"
 };

 vector <string> Meeting =
 {
    "كان الحضور في الاجتماع مناسباً بالنسبة لأعضاء اللجنة.",
    "لم يكن عدد الحضور من أعضاء اللجنة جيداً في الاجتماع."
 };

 vector <string> Tasks =
 {
    "تم الانتهاء نم تسليم التاسكات بشكل مناسب",
    "لم يتم الانتهاء من تسليم التساكات بعد."
 };

 vector <string> Training = 
 {
    "كان الحضور في جلسة التطوير مناسباً بالنسبة لأعضاء اللجنة.",
    "لم يكن عدد الحضور من أعضاء اللجنة جيداً في جلسة التطوير."
 };

vector <string> questions, answers, merits, demerits;

void questions_filler()
{
    questions.push_back("هل كانت أوضاع اللجنة على ما يرام؟");
    questions.push_back("هل استمرت حملات اللجنة في هذا الأسبوع؟");
    questions.push_back("هل تم عقد اجتماع؟");
    questions.push_back("هل تم توزيع بعض  التاسكات؟");
    questions.push_back("هل كانت هناك جلسات تدريب؟");
    questions.push_back("هل كان الرائد يقوم بدوره بشكل جيد؟");
    questions.push_back("هل كان الأعضاء يقوموا بدورهم بشكل جيد؟");
    questions.push_back("هل تم العمل على إيفنت؟");
    questions.push_back("هل كانت اللجنة في حالة نشاط؟"); //8
}

void ask(string question, bool& answer)
{
    cout << question << endl;
    string s;
    cin >> s;
    if (s == "نعم")
        answer = true;
    else
        answer = false;
}

string choose(vector <string> suggestions, bool f)
{
    string response = stable;
    if (!f)
        response += "عدم ";
    cout << choice << endl;
    int cnt = 1;
    for (auto it : suggestions) 
    {
        cout<< cnt << " - " << it << endl;
        cnt++;
    }

    int x;
    cin >> x;
    response = response + suggestions[x-1];

    while(true)
    {
        int cnt = 1;
        for (auto it : suggestions) 
        {
            cout<< cnt << " - " << it << endl;
            cnt++;
        }
        cout << endl;
        cout << choose_again << endl;
        cin >> x;
        if (x > 0)
            response = response + " و" + suggestions[x-1];
        else
            break;
    }
    return response;
}

string choose1(vector <string> suggestions, bool& f)
{
    string response = "و";
    cout << choice << endl;
    int cnt = 1;
    for (auto it : suggestions) 
    {
        cout<< cnt << " - " << it << endl;
        cnt++;
    }

    int x;
    cin >> x;
    response = response + suggestions[x-1];
    if (x == 1)
        f = true;
    else
        f = false;
    return response;
}

void committe_answers_filler()
{
    answers.push_back("كانت أوضاع اللجنة كما يلي:");
    ask(questions[0], estability);
    if (estability)
        answers.push_back("كانت اللجنة مستقرة " + choose(Estability, estability));
    else
        answers.push_back("لم تكن اللجنة مستقرة "+ choose(Estability, estability));
    
    ask(questions[1], campaign);
    if (campaign)
        answers.push_back("استمرت حملة .... بالعمل في اللجنة بدون انقطاع.");
    else
        answers.push_back("لم تستمر حملة .... في هذا الأسبوع.");

    ask(questions[2], meeting);
    if (meeting)
        answers.push_back("تم عقد اجتماع في اللجنة عن.... في هذا الأسبوع، " + choose1(Meeting, good_audience));
    else
        answers.push_back("لم يكن هناك اجتماع في هذا الأسبوع.");

    ask(questions[3], tasks);
    if (tasks)
        answers.push_back("تم توزيع بعض التاسكات الخاصة ب.... في اللجنة، "+ choose1(Tasks, done_taskts));

    ask(questions[4], training);
    if (training)
        answers.push_back("كان هناك لجنة تطوير عن ....، "+ choose1(Training, good_training));
    else
        answers.push_back("لم يكن هناك لجنة تدريب في هذا الأسبوع.");

    ask(questions[5], good_leader);
    if(good_leader)
        answers.push_back("كان الرائد يقوم بدوره بشكل جيد في هذا الأسبوع.");
    else
        answers.push_back("لم يكن لرائد اللجنة دور مؤثر في هذا الأسبوع.");

    ask(questions[6], good_member);
    if(good_member)
        answers.push_back("كان الأعضاء يقوموا بدورهم بشكل جيد حيث ");
    else
        answers.push_back("لم يقم الأعضاء بدورهم بشكل جيد ");

    ask(questions[7], event_work);
    if(event_work)
        answers.push_back("بدأ العمل على إيفنت .... في هذا الأسبوع حيث");
    
    ask(questions[8], active);
    if(active)
        answers.push_back("كان نشاط  اللجنة كبير وواضح في هذا الأسبوع ");
    else
        answers.push_back("كان هناك خمول كبير من اللجنة.");
}

void pros_cons_filler()
{
    if (campaign)
        merits.push_back("من الجيد استمرار الحملة إلى الآن بدون انقطاع.");
    else
        demerits.push_back("ليس من الجيد انقطاع حملة ... بدون سبب واضح.");

    if (meeting & good_audience)
        merits.push_back("حضور اللجنة المناسب سيؤدي إلى نتائج وآثار أفضل على اللجنة بكل تأكيد.");
    else if (meeting & !good_audience)
        demerits.push_back("عدم الحضور المناسب من أعضاء اللجنة سيكون منؤثر بالسلب على اللجنة وعلى الفرع.");

    if (tasks & done_taskts)
        merits.push_back("تم الانتهاء من تسليم التاسكات بشكل سريع وواضح.");
    else if (tasks & !done_taskts)
        demerits.push_back("كان هناك تأخير في تسليم التاسكات ولم يكن هناك أي اعتبار لسياسة الاعتذار.");
    
    if (good_leader)
        merits.push_back("كان رائد اللجنة إيجابي بشكل كبير مما يؤثر على أعضاء اللجنة بشكل إيجابي جيد.");
    
    if (active)
        merits.push_back("كانت من الواضح نشاط اللجنة في الأسبوع الأخير.");
    else
        demerits.push_back("كان هناك خمول من عدد كبير من أعضاء اللجنة.");

    answers.push_back("الإيجابيات :");
    for (auto it : merits)
        answers.push_back(it);
    
    answers.push_back("السلبيات : ");
    for (auto it : demerits)
        answers.push_back(it);
}


int main()
{
    Bug_Busters();
    questions_filler();
    committe_answers_filler();
    pros_cons_filler();
    ofstream outputFile("output.docx");
    for (auto it : answers)
        outputFile << it << endl;
    outputFile.close();

    return 0;
}