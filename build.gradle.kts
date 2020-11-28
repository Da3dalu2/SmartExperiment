plugins {
    java
    application
    id("com.github.johnrengelman.shadow") version "5.2.0"
}
repositories {
    mavenCentral()
    jcenter()
}

val javaFXModules = listOf(
    "base",
    "controls",
    "fxml",
    "swing",
    "graphics"
)

val supportedPlatforms = listOf("linux", "mac", "win")

dependencies {

    // Jfreechart library
    compile("org.jfree:jfreechart-fx:1.0.1")
    compile("org.jfree:jfreechart:1.5.1")
    compile("org.jfree:fxgraphics2d:1.8")

    // Jssc
    compile("org.scream3r:jssc:2.8.0")

    for (platform in supportedPlatforms) {
        for (module in javaFXModules) {
            implementation("org.openjfx:javafx-$module:13:$platform")
        }
    }

    testImplementation("org.junit.jupiter:junit-jupiter-api:5.5.2")
    testRuntimeOnly("org.junit.jupiter:junit-jupiter-engine:5.5.2")
}

tasks.withType<Test> {
    useJUnitPlatform()
}

application {
    mainClassName = "application.Launcher"
}
