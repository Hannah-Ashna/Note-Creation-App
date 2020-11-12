# Note-App
Created this small project to get more hands-on experience using the **boost::program_options** library. The program's concept is pretty simple, it allows the user to create a file using a name that's parsed to it via a command-line option. I'm looking to expand on this a little further and enable more file modification options (i.e. append, delete, etc.)


### Setup:
* Clone this repo first: `git clone https://github.com/Hannah-Ashna/Note-Creation-App.git` 
* Then run `make` via your command line within the folder.
* This will generate the `note_app` that you can then test out by running `note_app` via your CLI.

### Program Options:
* `--help` Displays all the options available  
* `--start [FileName]` Creates a new .txt file using the given file name
