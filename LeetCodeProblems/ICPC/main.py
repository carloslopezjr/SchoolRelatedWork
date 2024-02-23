# Ask user what movie they want to watch from a list of movies
# Give movie description and the year it came out
# Ask user if there is another movie they would like to watch
carsYear = str(2006)
duneYear = str(2021)
rubberYear = str(2010)

duneInfo = "A noble family becomes embroiled in a war for control over the galaxy's\
        most valuable asset while its heir becomes troubled by visions of a dark future."
        
carsInfo = "On the way to the biggest race of his life, a hotshot rookie race car\
    gets stranded in a rundown town and learns that winning isn't everything in life."
    
rubberInfo = "A homicidal car tire, discovering it has destructive psionic power,\
    sets its sights on a desert town once a mysterious woman becomes its obsession."
    
movies = ["Dune", "Cars", "Rubber"]
    
   

while True:
    selection = input("What movie would you like to learn more about? ")

    if selection == "What movies are there?":
        print(movies)
    if selection == "Dune":
        print(f"The movie Dune is about {duneInfo} It came out in the year {duneYear}")
    elif selection == "Cars":
        print(f"The movie Cars is about {carsInfo} It came out in the year {carsYear}")
    elif selection == "Rubber":
        print(f"The movie Rubber is about {rubberInfo} It came out in the year {rubberYear}")
    elif selection == "":
        print("Please pick a movie")