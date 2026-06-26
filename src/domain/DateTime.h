#include "Date.h"
#include "Time.h"
class DateTime
{
    public:
    DateTime();

    DateTime(const Date& d, const Time& t);

    DateTime(int year,
                int month,
                int day,
                int hour,
                int minute,
                int second);

    Date& getDate();
    const Date& getDate() const;

    Time& getTime();
    const Time& getTime() const;

    static DateTime now();

    bool operator<(const DateTime& other) const;
    bool operator>(const DateTime& other) const;
    bool operator<=(const DateTime& other) const;
    bool operator>=(const DateTime& other) const;
    bool operator==(const DateTime& other) const;
    friend std::ostream& operator<<(std::ostream& os, const DateTime& dt);

    static bool isValidDateTime(DateTime dt);

    private:
    Date date;
    Time time;
};