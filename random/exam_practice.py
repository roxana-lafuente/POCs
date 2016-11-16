topic = "german"
definitions = {
    "articles": [("Mann", "der"), ("Frau", "die")]
}

# Show options
print "Welcome to the %s training center!" % topic
print "\nAvailable units are:"
for k in definitions.keys():
    print "* %s" % k

# Get option
unit = raw_input("\nSelect which unit you would like to practice:\n")
ok_answers = 0

i = 0
if unit in definitions.keys():
    total = len(definitions[unit])
    print "\nStarting testing mode."
    for question, correct_answer in definitions[k]:
        i += 1
        answer = raw_input("Question %d out of %d: %s %s\n" % (i, total, "_" * len(correct_answer), question))
        if answer == correct_answer:
            print "OK!"
            ok_answers += 1
        else:
            print "Not OK. Correct answer was: %s." % correct_answer
    print "\nYou answered correctly %d questions out of %d (%d%%)" % (ok_answers, total, int(ok_answers/float(total) * 100))
else:
    print "\nUndefined '%s' unit. Please select another option." % unit