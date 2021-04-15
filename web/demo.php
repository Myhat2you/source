<?php
    $max_machines = 5;
    $name = $loc = $pin = $status = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST["txtName"];
        //$loc = test_input($_POST["txtLocation"]);
        //$pin = test_input($_POST["numPin"]);
        //$stat = test_input($_POST["numStatus"]);
        print "Hello there, $name\n";
    }

      
      function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
      }
?>