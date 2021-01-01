from datetime import datetime
from operator import attrgetter

def sort_people(people):
    for per_index in range(len(people)):
        people[per_index].birth_date = datetime.strptime(people[per_index].birth_date, "%d.%m.%Y")
    sorted_people = sorted(people, key=attrgetter('birth_date', 'last_name', 'first_name'))
    for per_index in range(len(sorted_people)):
        sorted_people[per_index].birth_date = sorted_people[per_index].birth_date.strftime("%d.%m.%Y")
    return sorted_people
