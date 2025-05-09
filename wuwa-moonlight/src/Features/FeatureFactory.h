#pragma once
#include <memory>
#include <functional>
#include <string>
#include <nlohmann/json.hpp>

class IFeatureFactory {
public:
    virtual ~IFeatureFactory() = default;
    
    virtual void Render() = 0;
    virtual void Draw() = 0;
    virtual void Run() = 0;
    virtual void RenderDebug() = 0;
    virtual bool IsEnable() = 0;
    
    // Метод Call с пустой реализацией по умолчанию
    virtual void Call(SDK::UObject* Object, SDK::UFunction* Function, void* Parms) {}
    
    // Сериализация и десериализация конфигурации
    virtual nlohmann::json Serialize() const = 0;
    virtual void Deserialize(const nlohmann::json& json) = 0;
    
    // Получить имя фичи
    virtual const std::string& GetFeatureName() const = 0;
    
    // Factory method to create instances
    template<typename T, typename... Args>
    static std::shared_ptr<T> Create(Args&&... args) {
        static_assert(std::is_base_of_v<IFeatureFactory, T>, "T must derive from IFeatureFactory");
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
};

class FeatureFactory : public IFeatureFactory {
protected:
    bool bEnable{ false };
    bool bOnce{ false };
    std::string featureName{ "Unknown" };
    
public:
    FeatureFactory() = default;
    FeatureFactory(std::string name) : featureName(std::move(name)) {}
    ~FeatureFactory() override = default;
    
    void Render() override {
        // Basic implementation
    }

    void RenderDebug() override {
        // Basic implementation
    }
    
    void Draw() override {
        // Basic implementation
    }
    
    void Run() override {
        // Basic implementation
    }
    
    void Call(SDK::UObject* Object, SDK::UFunction* Function, void* Parms) override {
        // Basic implementation
    }

    bool IsEnable() override {
        return bEnable;
    }
    
    // basic serialization impl
    nlohmann::json Serialize() const override {
        nlohmann::json j;
        j["enabled"] = bEnable;
        return j;
    }
    
    void Deserialize(const nlohmann::json& json) override {
        if (json.contains("enabled")) {
            bEnable = json["enabled"].get<bool>();
        }
    }
    
    const std::string& GetFeatureName() const override {
        return featureName;
    }
    
    void SetFeatureName(const std::string& name) {
        featureName = name;
    }
};

// Example of a custom factory implementation
class CustomFeature : public FeatureFactory {
private:
    std::string m_name;
    int m_id{0};

public:
    CustomFeature(std::string name, int id) : FeatureFactory(name), m_name(std::move(name)), m_id(id) {}
    
    void Render() override {
        // Custom rendering logic
        FeatureFactory::Render(); // Call base implementation if needed
    }
    
    void Draw() override {
        // Custom drawing logic
        FeatureFactory::Draw(); // Call base implementation if needed
    }
    
    // Переопределение сериализации для сохранения дополнительных полей
    nlohmann::json Serialize() const override {
        auto j = FeatureFactory::Serialize();
        j["custom_name"] = m_name;
        j["id"] = m_id;
        return j;
    }
    
    // Переопределение десериализации для загрузки дополнительных полей
    void Deserialize(const nlohmann::json& json) override {
        FeatureFactory::Deserialize(json);
        if (json.contains("custom_name")) {
            m_name = json["custom_name"].get<std::string>();
        }
        if (json.contains("id")) {
            m_id = json["id"].get<int>();
        }
    }
    
    // Custom methods
    constexpr int GetID() const noexcept { return m_id; }
    const std::string& GetName() const noexcept { return m_name; }
};

/*
// Example usage:
auto factory = ICFactory::Create<CustomFactory>("MyFeature", 42);
factory->Render();
factory->Draw();
int id = factory->GetID(); // Access custom methods
*/