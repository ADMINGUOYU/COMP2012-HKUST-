// Note that after compilation <Person* this> will be automatically added to code
// Like Python code -> function(self, param1, param2 ...)

void Person::have_child(Person* this, Person* baby)
{
    this->_child = baby;
}
