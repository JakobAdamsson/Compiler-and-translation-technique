else if ((*child)->type == "FCall")
{
    auto grand_child1 = std::next((*child)->children.begin(), 0);
    auto grand_child2 = std::next((*child)->children.begin(), 1);
    if ((*grand_child1)->type == "Identifier")
    {
        // Lookvariabel up på identifiern för current_class för att kolla att den variabeln är deklarerad
        Record *check_identifier = symboltable->lookup((*grand_child1)->value);
        if (!check_identifier)
        {
            symboltable->add_error((*grand_child1)->lineno, "Identifier " + (*grand_child1)->value + " not declared");
        }
        (*grand_child1)->print_node("heeej");
        check_identifier->printRecord();
        // Göra en lookup på den datatypen för att kolla att den classen är deklarerad
        Record *check_class = symboltable->lookup(check_identifier->dtype); // BLIR FEL HÄR!
        if (!check_class)
        {
            symboltable->add_error((*grand_child1)->lineno, "Class " + check_identifier->dtype + " not declared");
        }
        Class *check_class_class = dynamic_cast<Class *>(check_class);

        if (check_class_class == nullptr)
        {
            symboltable->add_error((*grand_child1)->lineno, "Class cast failed: " + check_identifier->dtype);
        }
        check_class_class->printRecord();
        // göra en lookupmethod lookupmethod för child->value på den klassen
        // Method *check_method = check_class_class->lookupMethod((*grand_child2)->value);
        // if (check_method == nullptr)
        // {
        //     symboltable->add_error((*grand_child2)->lineno, "Method " + (*grand_child2)->value + " not declared in class: " + check_class_class->id);
        // }
        std::cout
            << "Kommer vi hit? " << std::endl;
    }
    else if ((*grand_child1)->type == "NewVar")
    {
        // göra en look up grand_child1 dtype som ska vara en klass
        //  göra en lookupmethod för child -> value på den klassen
    }
    else if ((*grand_child1)->type == "FCall")
    {
    }
    else if ((*grand_child1)->type == "This")
    {
    }
    else
    {
    }
}