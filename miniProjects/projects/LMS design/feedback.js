document.addEventListener("DOMContentLoaded", function () {
  const feedbackForm = document.getElementById("feedbackForm");

  feedbackForm.addEventListener("submit", function (event) {
      event.preventDefault();

      // Get form values
      const name = document.getElementById("name").value;
      const email = document.getElementById("email").value;
      const feedback = document.getElementById("feedback").value;

      // Perform validation
      if (name.trim() === "" || email.trim() === "" || feedback.trim() === "") {
          alert("Please fill in all fields.");
          return;
      }

      alert("Thank you for your feedback!");

      // Reset the form
      feedbackForm.reset();

      // Redirect to project.html
      window.location.href = "project.html";
  });
});