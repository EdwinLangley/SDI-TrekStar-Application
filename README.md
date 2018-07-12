# SDIPROJECT

Repo for the Software Design and Implementation module

## User Guide

### The Interface
When the user opens up the application they will be greeted by the following interface:


![alt text](https://lh6.googleusercontent.com/UwAh2g6sHLRDrpgQC2aE_EmxMCXn9H__SR16NPhhkNoXthyM23Y394m1ZiGj3yjtnz4NWKvO1aW52Lott_-v=w1996-h2034-rw "Logo Title Text 1")



### Loading Stored Projects
The user does not need to worry about locating the previously added projects as this is handled automatically on start up from a comma separated values file stored locally to the application.
### Adding New Projects
If the user wishes to add a new project then they must navigate to the ‘New Project’ tab, enter the details about the project and select the create project button found on the bottom right

![alt text](https://lh6.googleusercontent.com/xTar9-7ZMh1O3jdY-ORELIGClKpqD5qkAfJTWfxCNWcZiw5YHtOqKjQ89wki9gwXT2iDXaR85BR93PKL4seu=w1996-h2034-rw "Logo Title Text 1")

Dependant on the status of the project selected the user might not be able to add ticket sales information. This is due to ticket sales only being relevant for projects with status “Now Playing”

As it is possible to have multiple items for the properties of locations and keywords, users enter single values into boxes and then proceed to press add.

If the user changes their mind about a location or keyword, they may highlight this value and then select the remove button - this will remove the item from the list.
### Adding Materials to Projects
When the user selects “Create Project”, if the project status is set to released, they will automatically be prompted to add a (or multiple) types of materials in the specific project window. This window also contains the general (core information regarding the project) and crew (information about crew assigned to the project) tabs, however these are not relevant for this stage.

![alt text](https://lh3.googleusercontent.com/QjyIO9bkyXCnMwf9PH6Mj6h0ixdKhrwqtpvZYGZTllGavR43Xpt5thpGNAPnTtSSpfRyk2DofySF9-FDMlUL=w1996-h2034-rw "Logo Title Text 1")

The user can start to add information about existing materials such as the type of material, video / audio formats, price and many more. 

A flag in the top right corner of the UI lets the user know if the material has been created and will automatically change when the user clicks “create” with the appropriate information added, or when the project is view and already had materials stored in the database.

To clear the project the user must click clear in the bottom left of the screen. This will remove the material and set the creation flag to not created.
### Adding Crew to Projects
The “Crew” tab in the project specific window can also be used to add crew members to the project. After navigating there, the tab will look like this: 

![alt text](https://lh6.googleusercontent.com/fJ-IzkXDDk3hVobJXxIjBzvDq8IjkQNeHlEO_WMekkEzr52DCUmZt9_7ods3PQSbO6-HohXQTrX9qPB2d0CM=w1996-h2034 "Logo Title Text 1")

The user can then proceed to add relevant information about the crew member such as their role, their name and their date of birth.

When the user has finished entering information about the crew member, they can select add which is situated near the center of the screen. The crew member will now be populated below.  

### Filtering Projects
To filter by project properties, the user can navigate to “Open Project”, here they will find a list of all of the previously added projects. The user has the option to filter by the following properties

No filter applied
Title 				(Requires extra text input)
Genre				(Requires extra text input)
Keywords			(Requires extra text input)
A-Z
Newest to oldest date
Oldest to newest date 
Director			(Requires extra text input)
Actor				(Requires extra text input)
Producer			(Requires extra text input)
Writer				(Requires extra text input)
Editor				(Requires extra text input)
Production Designer		(Requires extra text input)
Set Decorator			(Requires extra text input)
Costumer Designer 		(Requires extra text input)


![alt text](https://lh6.googleusercontent.com/fSHY1mTIwHwtYm_xidGAiVAqtR2TsARZ0bcQZ7_2Zb-rGAzxMeYQS8Nj2HexkPmhvYoM0bvvYvZccu5zxy2k=w1996-h2034 "Logo Title Text 1")

### Modifying Current Projects
If the user wishes to change some core properties relating to a specific project then they can navigate to the project using the filter functionality mentioned above. When the user selected open project all of the fields are still editable in the “General” tab.


When the user has finished making their changes, they can click apply changes and the modifications will appear in the project the next time it is used.
### Modifying Current Materials
If the user wishes to change some properties relating to a specific projects materials then they can navigate to the project using the filter functionality. When the user selected open project all of the fields are still editable in the “Materials” tab.

![alt text](https://lh6.googleusercontent.com/RjMAWVQweqaR6Ah-BODBWud9Z32xK17EOW4pCjCZGYOYCHSRe8tpSc4HEMDZuwT6CU1JHPdjEAhD4F3v8Aym=w1996-h2034 "Logo Title Text 1")

When the user has finished making their changes, they can click apply changes and the modifications will appear in the materials the next time it is used.
### Modifying Current Crew
If the user wishes to change some properties relating to a specific projects crew then they can navigate to the project using the filter functionality. When the user selected open project all of the fields are still editable in the “Crew” tab.

The user will need to select the crew member from the populated list and delete them. The user is now free to add another crew member under the same name and role with the new information.



### Saving Projects
The user does not need to worry about the process of saving files. The close function has been overridden to save all of the current, projects, materials and crew into a character delimited file  stored locally to the application. 













![alt text](https://lh6.googleusercontent.com/Jii5dtvLqDDI-tGLTZ4bH957AdQ6Wff8sUUzFRtbojnKOgJiGwkbY4PrzoiHx5yd_lUj_ripxTFeGvtjy3B_=w1996-h2034-rw "Logo Title Text 1")

![alt text](https://lh4.googleusercontent.com/KjS3_HqQ5QZahbLQuf122l3-MVYkTmSpGzza55qZndOIiLKdjraNU8LgH58hDVSlWV0Ctpbe8zArnLZ1gwgv=w1996-h2034 "Logo Title Text 1")
