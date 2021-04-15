<?php
    $max_machines = 5;
    $name = $loc = $pin = $status = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST["txtName"];
        #$name = test_input($_POST["txtName"]);
        #$loc = test_input($_POST["txtLocation"]);
        #$pin = test_input($_POST["numPin"]);
        #$stat = test_input($_POST["numStatus"]);

        print "Name $name\n";
        #print "Location $loc\n";
        #print "Pin $pin\n";
        #print "Status $stat\n";
    }
      
      function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
      }
?>

<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Arial, Helvetica, sans-serif;}
* {box-sizing: border-box;}

input[type=text], select, textarea {
  width: 100%;
  padding: 12px;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
  margin-top: 6px;
  margin-bottom: 16px;
  resize: vertical;
}

input[type=number], select, textarea {
  width: 100%;
  padding: 12px;
  border: 1px solid #ccc;
  border-radius: 4px;
  box-sizing: border-box;
  margin-top: 6px;
  margin-bottom: 16px;
}

input[type=submit] {
  background-color: #4CAF50;
  color: white;
  padding: 12px 20px;
  border: none;
  border-radius: 4px;
}

.container {
  border-radius: 5px;
  background-color: #f2f2f2;
  padding: 20px;
}
</style>
</head>
<body>

<h3>Add Machine</h3>
<div class="container">
  <form method="post" action="/cgi-bin/output.o">
    <label for="mName">Name</label>
    <input type="text" name="mName" id="txtName">

    <label for="mLoc">Location</label>
    <input type="text" name="mLoc" id="txtLocation">
    
    <label for="mPin">Pin</label>
    <input type="number" name="mPin" id="numPin" min="0" max="27">

    <label for="mState">State</label>
    <input type="number" name="mState" id="numState" min="0" max="1">

    <input type="submit" value="Submit">
  </form>
</div>